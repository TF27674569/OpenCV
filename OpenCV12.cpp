#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;
/**
 * ��дֱ������
 */


 /**
  * ֱ��ͳ��
  * ����Ĭ��д����ͳ������[0,255]
  */

void _calcHist(const Mat &input,Mat &output) 
{
	// ֻ��1�� 256�е�int����
	output=Mat::zeros(1, 256, CV_32S);

	// ͳ�� 0-255�����ڣ����ص�ֵ�ֲ������
	for (int row = 0; row < input.rows; row++)
	{
		for (int col = 0; col < input.cols; col++)
		{
			// ���ֵ�ķ�Χ0-255,�պ���Ϊͳ��ͼ�ĽǱ�
			uchar pix_value = input.at<uchar>(row, col);
			// ÿ����һ�Σ�ֵ+1
			output.at<int>(0, pix_value) += 1;
		}
	}
}


/**
 * ��һ�������ֵΪmax_value[0,max_value]��
 * ��_calcHistͳ��֮�󣬽�_calcHistͳ�ƺ�Ľ�������ֵ�����1�������ֵ�����μ�С
 * ��Ϊ��������дֱ��ͳ��ʱĬ��ʹ����һά���飬����һ��forѭ���Ϳ�����
 */
void _normalize(const Mat& input, Mat& output,int max_value)
{
	int hist_max = 0;
	// ֻ��1�� 256�е�int����
	for (int col = 0; col < input.cols; col++)
	{
		hist_max = max(hist_max, input.at<int>(0,col));
	}


	Mat des=Mat::zeros(input.size(),input.type());

	for (int col = 0; col < input.cols; col++)
	{
		// �õ�������ֵ��float�ӣ����������������
		float hist_value = input.at<int>(0, col);
		// �õ�С�����ֵ
		float normalize_value = hist_value / hist_max;
		// max_value���������ֵתΪmax_value
		int normalize = normalize_value * max_value;
		des.at<int>(0, col) = normalize;
	}

	output = des.clone();
}

// 1. ֱ��ͼ��ͳ��
// 2. ����ֱ��ͼ�����صĸ���
// 3. ����һ��ӳ���
// 4. ��ӳ����в��Ҹ�ֵ
void _equalizeHist(const Mat& input, Mat& output)
{
	Mat hist;
	// �Զ���ֱ��ͼ
	_calcHist(input, hist);

	// ������ĳһ��ֵ���ֵĸ���[0,255]�е�0�γ��ֵĸ���
	Mat prob_mat(hist.size(), CV_32FC1);

	// ���е����ص���
	int all_pixs = input.rows * input.cols;

	for (int i = 0; i < hist.cols; i++)
	{
		// ����=���ֵĴ���/�ܸ���
		prob_mat.at<float>(0, i) = 1.0* hist.at<int>(0, i) / all_pixs;
	}
	

	// ���㵽�����ʱ���ۼӸ���
	float sum_pro = 0;
	for (int i = 0; i < prob_mat.cols; i++)
	{
		sum_pro += prob_mat.at<float>(0, i);
		// ����=���ֵĴ���/�ܸ���
		prob_mat.at<float>(0, i) = sum_pro;
	}

	// ����ӳ��� = ��ǰ����*255   �õ��Ľ������[0,255]
	Mat map(hist.size(), CV_32FC1);
	for (int i = 0; i < prob_mat.cols; i++)
	{
		float prob = prob_mat.at<float>(0, i);
		map.at<float>(0, i) = prob * 255;
	}

	// ����ӳ�� 
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
	// �Զ���ֱ��ͼ
	//_calcHist(gray, hist);

	//_normalize(hist, hist, 255);
	//  ��ֱ��ͼ
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