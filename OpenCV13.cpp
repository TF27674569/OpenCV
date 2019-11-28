#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;

/**
 * size:ģ��ֱ��������˵�size
 */
void blur(const Mat& src, Mat& dst, int size) {
	// 1.�����ԭͼ
	Mat mat;
	int radius = size >> 1;
	// BORDER_DEFAULT�ܱ�ֵ��䣬���radius�Ĵ�С
	copyMakeBorder(src,mat, radius, radius, radius, radius,BORDER_DEFAULT);
	// 2.�������ͼ
	// InputArray src
	// OutputArray sum       ���غ�
	// OutputArray sqsum     ����ƽ����
	// int sdepth = -1       sum ���   �����ԭͼ�Ĵ�����ѡint����
	// int sqdepth = -1      sqsum ���  �����ԭͼ�Ĵ�����ѡint����
	Mat sum;
	integral(mat, sum, CV_32S);
	//Mat sqsum;
	//integral(mat, sum, sqsum,CV_32S,CV_32S);

	dst.create(src.size(),src.type());

	int channels = src.channels();
	// 3.ʹ�þ�ֵģ����ͼ�����ģ������
	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			int x0 = col;
			int y0 = row;
			int x1 = col + size;
			int y1 = row + size;

			// �Ը�����ɫͨ�����д���
			for (int i = 0; i < channels; i++)
			{
				// ��ȡ�ĸ����ڻ���ͼ�е�ֵ ÿ�������Ǿֲ���ɫֵ�ĺͣ�����ֵ�����ֵ�ᱻ�Ŵ󣬹�ʹ��Vec3i��ÿ��ͨ����intȡ�������ʱ��Ҳ�Ǵ��CV_32S��int
				int lt = sum.at<Vec3i>(y0, x0)[i];
				int rt = sum.at<Vec3i>(y0, x1)[i];
				int lb = sum.at<Vec3i>(y1, x0)[i];
				int rb = sum.at<Vec3i>(y1, x1)[i];

				// ��ĺ�
				// ĳһ�������ֵ = ���ڵ����½ǣ�����ͼ�� + ��������Ͻ� - ��������� - ���������
				int sum_pix = rb + lt - rt - lb;
				//  sum_pix / (size * size) ��ƽ��ֵ
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