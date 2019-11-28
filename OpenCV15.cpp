#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "OpenCV14.h"

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/demo1.png");

	if (!src.data)
	{
		printf("src imread error");
		return -1;
	}
	imshow("src", src);



	waitKey(0);
	return 0;
}