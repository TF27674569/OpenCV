#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;
/**
 * 手写直方均衡
 */


 /**
  * 直方统计
  * 这里默认写死，统计区间[0,255]
  */

void _calcHist(const Mat &input,Mat &output) 
{
	// 只有1行 256列的int数据
	output=Mat::zeros(1, 256, CV_32S);

	// 统计 0-255区间内，像素点值分布的情况
	for (int row = 0; row < input.rows; row++)
	{
		for (int col = 0; col < input.cols; col++)
		{
			// 这个值的范围0-255,刚好作为统计图的角标
			uchar pix_value = input.at<uchar>(row, col);
			// 每落下一次，值+1
			output.at<int>(0, pix_value) += 1;
		}
	}
}


/**
 * 归一化（最大值为max_value[0,max_value]）
 * 经_calcHist统计之后，将_calcHist统计后的结果，最大值，变成1，其余的值，依次减小
 * 因为这里我们写直方统计时默认使用了一维数组，所以一层for循环就可以了
 */
void _normalize(const Mat& input, Mat& output,int max_value)
{
	int hist_max = 0;
	// 只有1行 256列的int数据
	for (int col = 0; col < input.cols; col++)
	{
		hist_max = max(hist_max, input.at<int>(0,col));
	}


	Mat des=Mat::zeros(input.size(),input.type());

	for (int col = 0; col < input.cols; col++)
	{
		// 拿到的像素值用float接，下面好做除法运算
		float hist_value = input.at<int>(0, col);
		// 得到小数点的值
		float normalize_value = hist_value / hist_max;
		// max_value化，将这个值转为max_value
		int normalize = normalize_value * max_value;
		des.at<int>(0, col) = normalize;
	}

	output = des.clone();
}

// 1. 直方图的统计
// 2. 计算直方图中像素的概率
// 3. 生成一张映射表
// 4. 从映射表中查找赋值
void _equalizeHist(const Mat& input, Mat& output)
{
	Mat hist;
	// 自定义直方图
	_calcHist(input, hist);

	// 计算这某一段值出现的概率[0,255]中第0段出现的概率
	Mat prob_mat(hist.size(), CV_32FC1);

	// 所有的像素点数
	int all_pixs = input.rows * input.cols;

	for (int i = 0; i < hist.cols; i++)
	{
		// 概率=出现的次数/总个数
		prob_mat.at<float>(0, i) = 1.0* hist.at<int>(0, i) / all_pixs;
	}
	

	// 计算到这个段时的累加概率
	float sum_pro = 0;
	for (int i = 0; i < prob_mat.cols; i++)
	{
		sum_pro += prob_mat.at<float>(0, i);
		// 概率=出现的次数/总个数
		prob_mat.at<float>(0, i) = sum_pro;
	}

	// 生成映射表 = 当前概率*255   得到的结果还是[0,255]
	Mat map(hist.size(), CV_32FC1);
	for (int i = 0; i < prob_mat.cols; i++)
	{
		float prob = prob_mat.at<float>(0, i);
		map.at<float>(0, i) = prob * 255;
	}

	// 反向映射 
	output.create(input.size(), input.type());
	for (int row = 0; row < input.rows; row++)
	{
		for (int col = 0; col < input.cols; col++)
		{
			uchar index = input.at<uchar>(row, col);
			output.at<uchar>(row, col) = map.at<float>(0, index);
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

	Mat gray;
	cvtColor(src,gray,COLOR_BGR2GRAY);
	imshow("gray", gray);

	//Mat hist;
	// 自定义直方图
	//_calcHist(gray, hist);

	//_normalize(hist, hist, 255);
	//  画直方图
	//int bin_w = 5;
	//int grad = 256;
	//Mat hist_mat(grad, bin_w * 256, CV_8UC3);
	//for (int i = 0; i < grad; i++)
	//{
	//	Point start(i * bin_w, hist_mat.rows);
	//	Point end(i * bin_w, hist_mat.rows - hist.at<int>(0, i));
	//	line(hist_mat, start, end, Scalar(255, 0, 0), bin_w, LINE_AA);
	//}
	//imshow("des", hist_mat);

	Mat dst;
	_equalizeHist(gray, dst);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}
*/