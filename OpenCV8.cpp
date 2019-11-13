#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;



int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/gl.png");

	if (!src.data)
	{
		cout << "imread error" << endl;
		return -1;
	}

	imshow("src",src);

	// 1.先用Canny检测出边缘
	Mat canny;
	Canny(src,canny,40,120);
	imshow("canny",canny);

	// 2.霍夫直线检测
	vector<Vec4f> lines;
	//InputArray image    检测的图
	//OutputArray lines   得到的线
	//double rho          像素的扫描间隙，扫描时像素与像素之间隔几个像素
	//double theta        函数r=x*cosα+y*sinα这个角度每次增加的值
	//int threshold       低阈值这个点的值必须大于threshold才认为是一个点（否则这个点即使在线上，也将去除）
	//double minLineLength = 0   这条线最少要包含多少个点（少于这个值，就不认为是线）
	//double maxLineGap = 0      Canny 之后连续的线中间可能会有断开点，如果这个断开的点在maxLineGap之内，也将认为是这条线的一部分
	HoughLinesP(canny, lines,1,CV_PI/180,170,30,70);

	for (int i = 0; i < lines.size(); i++)
	{
		Vec4f pline = lines[i];

		line(src, Point(pline[0], pline[1]), Point(pline[2], pline[3]),Scalar(0,0,255),4);
	}

	imshow("resule", src);
	
	waitKey(0);
	return 0;
}
