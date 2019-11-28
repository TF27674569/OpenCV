#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;

/**
 * size:模糊直径，卷积核的size
 */
void blur(const Mat& src, Mat& dst, int size) {
	// 1.先填充原图
	Mat mat;
	int radius = size >> 1;
	// BORDER_DEFAULT周边值填充，填充radius的大小
	copyMakeBorder(src,mat, radius, radius, radius, radius,BORDER_DEFAULT);
	// 2.计算积分图
	// InputArray src
	// OutputArray sum       像素和
	// OutputArray sqsum     像素平方和
	// int sdepth = -1       sum 深度   必须比原图的大，这里选int类型
	// int sqdepth = -1      sqsum 深度  必须比原图的大，这里选int类型
	Mat sum;
	integral(mat, sum, CV_32S);
	//Mat sqsum;
	//integral(mat, sum, sqsum,CV_32S,CV_32S);

	dst.create(src.size(),src.type());

	int channels = src.channels();
	// 3.使用均值模糊对图像进行模糊操作
	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			int x0 = col;
			int y0 = row;
			int x1 = col + size;
			int y1 = row + size;

			// 对各个颜色通道进行处理
			for (int i = 0; i < channels; i++)
			{
				// 获取四个点在积分图中的值 每个点存的是局部颜色值的和，所以值求出的值会被放大，故使用Vec3i用每个通道用int取读，存的时候也是存的CV_32S的int
				int lt = sum.at<Vec3i>(y0, x0)[i];
				int rt = sum.at<Vec3i>(y0, x1)[i];
				int lb = sum.at<Vec3i>(y1, x0)[i];
				int rb = sum.at<Vec3i>(y1, x1)[i];

				// 块的和
				// 某一块的像素值 = 块内的右下角（积分图） + 快外的左上角 - 快外的右上 - 块外的左下
				int sum_pix = rb + lt - rt - lb;
				//  sum_pix / (size * size) 求平均值
				dst.at<Vec3b>(row,col)[i] = sum_pix / (size * size);
			}

		}
	}
}

/*
int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/test.txt");

	if (!src.data)
	{
		printf("src imread error");
		return -1;
	}

	imshow("src", src);

	Mat dst;
	blur(src, dst, 55);

	imshow("dst",dst);

	waitKey(0);
	return 0;
}
*/