#include  <stdio.h>
#include  <stdlib.h>
#include  <opencv2/opencv.hpp>
#include  <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;


/*
Mat ����,�ͳ��ú���
*/

/*
int main()
{

	// imread ��ȡһ��ͼƬ������һ��mat����
	Mat src = imread("C:/Users/ubt/Desktop/image1.png");

	if (!src.empty)
	{
		printf("src imread error");
		return -1;
	}

	imshow("src", src);

	// �У��൱�ڿ�
	int cols = src.cols;
	// ��   ��
	int rows = src.rows;
	// ��ɫͨ��
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