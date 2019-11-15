#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;


/*
int main()
{
	//Mat src = imread("C:/Users/ubt/Desktop/gl.png");
	//Mat src = imread("C:/Users/ubt/Desktop/circle_demo.png");
	Mat src = imread("C:/Users/ubt/Desktop/test.jpg");

	if (!src.data)
	{
		cout << "imread error" << endl;
		return -1;
	}

	imshow("src",src);

	// 1.先用Canny检测出边缘
	//Mat canny;
	//Canny(src,canny,40,100);
	//imshow("canny",canny);

	// 2.霍夫直线检测
	//vector<Vec4f> lines;
	//InputArray image    检测的图
	//OutputArray lines   得到的线
	//double rho          像素的扫描间隙，扫描时像素与像素之间隔几个像素
	//double theta        函数r=x*cosα+y*sinα这个角度每次增加的值
	//int threshold       低阈值这个点的值必须大于threshold才认为是一个点（否则这个点即使在线上，也将去除）
	//double minLineLength = 0   这条线最少要包含多少个点（少于这个值，就不认为是线）
	//double maxLineGap = 0      Canny 之后连续的线中间可能会有断开点，如果这个断开的点在maxLineGap之内，也将认为是这条线的一部分
	//HoughLinesP(canny, lines,1,CV_PI/180,170,30,70);

	//for (int i = 0; i < lines.size(); i++)
	//{
	//	Vec4f pline = lines[i];

	//	line(src, Point(pline[0], pline[1]), Point(pline[2], pline[3]),Scalar(0,0,255),4);
	//}

	//3.霍夫圆检测
	vector<Vec3f> circes;
	//InputArray image           检测图
	//OutputArray circles        得到的圆（圆心和半径）
	//int method                 圆只支持HOUGH_GRADIENT
	//double dp                  为第一阶段所使用的霍夫空间的分辨率，dp=1时表示霍夫空间与输入图像空间的大小一致，dp=2时霍夫空间是输入图像空间的一半，以此类推
	//double minDist             圆心之间的最小距离，如果检测到的两个圆心之间距离小于该值，则认为它们是同一个圆心
	//double param1 = 100        投票累加结果超过多少才能算圆（有多少个点）表示传递给canny边缘检测算子的高阈值，而低阈值为高阈值的一半。
	//double param2 = 100        低阈值  中心点累加器阈值 – 候选圆心。它越小的话，就可以检测到更多根本不存在的圆，而它越大的话，能通过检测的圆就更加接近完美的圆形了。
	//int minRadius = 0          最小的半径
	//int maxRadius = 0          最大的半径
	//HoughCircles(canny, circes, HOUGH_GRADIENT,1, src.rows / 5, 150, 70, 0, 0);

	//for (int i = 0; i < circes.size(); i++)
	//{
	//	Vec3f pcircle = circes[i];

	//	circle(src,Point(pcircle[0],pcircle[1]),pcircle[2],Scalar(0,0,255),3);
	//}


	Mat des;
	Mat mat_x(src.size(),CV_32FC1), mat_y(src.size(), CV_32FC1);



	// 此处将图像进行左右反转  点（x，y）变成（src.cols-x,y）,也就是左边的像素点的值用右边像素点的值去填充
	// 但是mat_x里面存的是x值对应的点在原图中点的位置，并不是像素值，mat_x和mat_y只是表示了一个规则
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			// 当前的x = 原来行的最后一个（位置不是像素值）
			mat_x.at<float>(i, j) = static_cast<float>(src.cols -j);
			// 当前的y  = 原来y的位置
			mat_y.at<float>(i, j) = i;
		}
	}


	//InputArray src    输入
	//OutputArray dst   输出
	//InputArray map1   重映射后点x对应原图的位置
	//InputArray map2   重映射后点y对应原图的位置
	//int interpolation 滤波方式，这里选则线性滤波
	remap(src, des, mat_x,mat_y, INTER_LINEAR);

	imshow("result", des);
	
	waitKey(0);
	return 0;
}
*/