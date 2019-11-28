#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "OpenCV14.h"

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;

/**
 * 求局部的和（或者平方和）
 * sum：积分图
 * x0,y0,  x1, y1：左上角和，右下角的两个点坐标
 * channel：通道数
 */
int getBlockSum(const Mat &sum,int x0, int y0, int x1, int y1,int channel) {
	// 左上+右下-右上-左下
	int lt = sum.at<Vec3i>(y0, x0)[channel];
	int rt = sum.at<Vec3i>(y1, x0)[channel];
	int lb = sum.at<Vec3i>(y0, x1)[channel];
	int rb = sum.at<Vec3i>(y1, x1)[channel];
	return lt+ rb- rt- lb;
}


/**
 * size：模糊半径
 * singam：求k值使用的一个值
 */
void integralBlur(const Mat &src, Mat &dst, int size, int sigma)
{
	// 在计算加积分图之前先将，src图像边缘填充一下,使用BORDER_DEFAULT，取边缘值
	Mat mat;
	int radius = size / 2;
	copyMakeBorder(src, mat, radius, radius, radius, radius, BORDER_DEFAULT);

	//1. 计算积分图得到积分图的像素和与积分图的像素平方和
	Mat sum_mat;
	Mat sqsum_mat;
	// 三通道颜色的积分图值可能超过CV_8UC3 使用CV_32S
	integral(mat, sum_mat, sqsum_mat,CV_32S, CV_32S);

	//2. 通过积分图求出，局部像素的和与局部像素的平方和
	// 输出图像
	dst.create(src.size(), src.type());

	// 通道数
	int channels = src.channels();

	// 块的像素个数
	int pix_area = size * size;

	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			int x0 = col;
			int y0 = row;
			int x1=  col+size;
			int y1 = row + size;

			// 计算各个通道的值
			for (int ch = 0; ch < channels; ch++)
			{

				//3. 通过公式计算方差
				// 需要 平方和 与 和的平方 
				// 先求和
				int sum = getBlockSum(sum_mat, x0, y0, x1, y1, ch);
				float sqsum = getBlockSum(sqsum_mat, x0, y0, x1, y1, ch);
				// 计算方差 1/n *( \sum_{i=1 }^{n}x(i)^2-1/n *( \sum_{i=1 }^{n}x(i))^2)
				// （sqsum - 1/像素个数*（sum的平方））/像素个数
				float diff_sum = (sqsum - sum * sum / pix_area) / pix_area;

				//4. 通过方差计算k
				float k = diff_sum / (diff_sum + sigma);

				//5. 通过局部的和求出局部平均值 = 局部像素和/像素个数
				float average_sum = sum / pix_area;

				//6. 通过k计算出当前像素的边缘保留后的值 =  (1-k)平均值+k*原像素值
				int pixels = src.at<Vec3b>(row, col)[ch];
				pixels = (1 - k)* average_sum + k * pixels;
				dst.at<Vec3b>(row, col)[ch] = pixels;
				
			}
		}
	}
}

/**
 *检测皮肤区域，皮肤区域为白255  其他区域为黑0
 */
void skinDetect(const Mat &src,Mat &dst) 
{
	dst.create(src.size(),CV_8UC1);
	Mat skin_ycbcr;
	cvtColor(src, skin_ycbcr, COLOR_BGR2YCrCb);

	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			Vec3b pixels = src.at<Vec3b>(row, col);
			uchar y = pixels[0];
			uchar cr = pixels[1];
			uchar cb = pixels[2];
			if (y > 80 && 85 < cb < 135 && 135 < cb < 180 )
			{
				dst.at<uchar>(row, col) = 255;
			}else {
				dst.at<uchar>(row, col) = 0;
			}
		}
	}
}
/**
 *通过皮肤检测后合并
 *如果是皮肤，使用blur滤波后的图片，否则使用原图
 *src：原图
 *blur：快速边缘滤波后的图
 *skin：做皮肤检测后的区域
 *skinMerge：返回的结果
 */
void skinMerge(const Mat &src, const Mat& blur, const Mat& skin, Mat& skinMerge)
{
	skinMerge.create(src.size(),src.type());
	
	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			uchar skin_value= skin.at<uchar>(row, col);
			if (skin_value==255)
			{
				skinMerge.at<Vec3b>(row, col) = blur.at<Vec3b>(row, col);
			}
			else 
			{
				skinMerge.at<Vec3b>(row, col) = src.at<Vec3b>(row, col);
			}
		}
	}

}


int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/demo1.png");

	if (!src.data)
	{
		printf("src imread error");
		return -1;
	}

	imshow("原图", src);

	// 快速边缘保留滤波
	Mat dst;
	int size = 15;
	integralBlur(src, dst, size, size* size);
	imshow("快速边缘滤波", dst);

	// 检测皮肤
	Mat skin;
	skinDetect(src, skin);
	imshow("检测皮肤", skin);

	// 合并
	Mat skin_merge;
	skinMerge(src,  dst, skin, skin_merge);
	imshow("合并", skin_merge);

	// 提升亮度
	add(skin_merge, Scalar(10, 10, 10), skin_merge);
	imshow("提升亮度", skin_merge);

	waitKey(0);
	return 0;
}