#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;


int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/test.txt");

	if (!src.data)
	{
		printf("src imread error");
		return -1;
	}

	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	imshow("gray", gray);


	waitKey(0);
	return 0;
}