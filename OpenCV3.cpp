#include  <stdio.h>
#include  <stdlib.h>
#include  <opencv2/opencv.hpp>
#include  <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;


/*
图像处理
*/
/*
int main()
{

	// imread 读取一张图片，返回一个mat对象
	Mat src = imread("C:/Users/ubt/Desktop/image1.png");

	if (!src.data)
	{
		printf("src imread error");
		return -1;
	}
	
	// 裁剪
	//Mat clipMat = src(Rect(0,0,200,200));


	//// 列（相当于宽）
	//int cols = clipMat.cols;
	//// 行   高
	//int rows = clipMat.rows;
	//// 颜色通道
	//int channels = clipMat.channels();

	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++)
	//	{
	//		uchar b = clipMat.at<Vec3b>(i,j)[0];
	//		uchar g = clipMat.at<Vec3b>(i, j)[1];
	//		uchar r = clipMat.at<Vec3b>(i, j)[2];

	//		uchar gray = 0.11f * r + 0.59f * g + 0.30f * r;
	//		clipMat.at<Vec3b>(i, j)[0]= gray;
	//		clipMat.at<Vec3b>(i, j)[1]= gray;
	//		clipMat.at<Vec3b>(i, j)[2]= gray;
	//	}

	//}

	//imshow("clipMat", src);
	//

	//Mat gray_opencv;
	//cvtColor(src,gray_opencv,COLOR_RGB2GRAY);
	//imwrite("C:/Users/ubt/Desktop/gray_opencv.png", gray_opencv);

	//Mat gray_user(src.rows,src.cols,CV_8UC1);
	//for (int i = 0; i < src.rows; i++)
	//{
	//	for (int j = 0; j < src.cols; j++)
	//	{
	//		uchar b = src.at<Vec3b>(i, j)[0];
	//		uchar g = src.at<Vec3b>(i, j)[1];
	//		uchar r = src.at<Vec3b>(i, j)[2];

	//		uchar gray = 0.11f * r + 0.59f * g + 0.30f * r;
	//		gray_user.at<uchar>(i, j) = gray;
	//	}

	//}
	//imshow("gray_user", gray_user);

	//imwrite("C:/Users/ubt/Desktop/gray_user.png", gray_user);
	
	// 图像混合 add函数和addWeighted函数
	//Mat addSrc = imread("C:/Users/ubt/Desktop/test.jpg");
	//Mat addSrc = imread("C:/Users/ubt/Desktop/image1.png");
	
	//Mat clipSrc = src(Rect(0,0,addSrc.cols,addSrc.rows));

	//addWeighted(clipSrc,0.0f,addSrc,1.0f,0, clipSrc);


	//float alpha = 2.0f;
	//float bate = 0;

	float alpha = 1.0f;
	float bate = 100;

	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			uchar b = src.at<Vec3b>(i, j)[0];
			uchar g = src.at<Vec3b>(i, j)[1];
			uchar r = src.at<Vec3b>(i, j)[2];


			src.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(b * alpha + bate);
			src.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(g * alpha + bate);
			src.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(r * alpha + bate);
		}

	}

	imshow("des", src);


	waitKey(0);
	return 0;
}
*/