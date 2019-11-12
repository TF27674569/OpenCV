#include  <stdio.h>
#include  <stdlib.h>
#include  <opencv2/opencv.hpp>
#include  <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;


/*
Mat 对象,和常用函数
*/

/*
int main()
{

	// imread 读取一张图片，返回一个mat对象
	Mat src = imread("C:/Users/ubt/Desktop/image1.png");

	if (!src.empty)
	{
		printf("src imread error");
		return -1;
	}

	imshow("src", src);

	// 列（相当于宽）
	int cols = src.cols;
	// 行   高
	int rows = src.rows;
	// 颜色通道
	int channels = src.channels();

	printf("cols=%d,rows=%d,channels=%d\n", cols, rows, channels);


	//Mat mat(30,30,CV_8UC1,Scalar(255));

	//Mat mat(3,3,CV_8UC3,Scalar(0,0,255));
	//imshow("mat", mat);
	//std::cout << mat << std::endl;

	//Mat copySrc;
	//src.copyTo(copySrc);
	//imshow("copySrc", copySrc);
	//printf("%p,%p",&src,&copySrc);


	Mat mat = src.clone();
	imshow("mat", mat);
	printf("%p,%p",&src,&mat);

	waitKey(0);
	return 0;
}
*/