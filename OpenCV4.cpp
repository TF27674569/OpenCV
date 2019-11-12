#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;

/*
int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/image1.png");

	if (!src.data)
	{
		cout << "src read error" << endl;
		return -1;
	}
	
	// »­Ïß line
	// InputOutputArray img, Point pt1, Point pt2, const Scalar& color,int thickness = 1, int lineType = LINE_8, int shift = 0
	//line(src,Point(0,100),Point(150,100),Scalar(0,200,0),2, LINE_4);

	// ÍÖÔ² ellipse
	//InputOutputArray img
	//Point center
	//Size axes
	//double angle
	//double startAngle
	//double endAngle,
	//const Scalar& color
	//int thickness = 1,
	//int lineType = LINE_8
	//int shift = 0
	//ellipse(src,Point(src.rows/2,src.cols/2),Size(50,30),0,0,360, Scalar(0, 200, 0),2,LINE_AA);


	// ¾ØÐÎ rectangle
	// InputOutputArray img
	// Point pt1
	// Point pt2,
	// const Scalar& color
	// int thickness = 1,
	// int lineType = LINE_8
	// int shift = 0
	//rectangle(src,Point(100,100),Point(200,200), Scalar(0, 0, 200),2, LINE_AA);

	// »­Ô² cicle
	// InputOutputArray img
	// Point center
	// int radius,
	// const Scalar& color
	// int thickness = 1,
	// int lineType = LINE_8
	// int shift = 0
	// circle(src, Point(src.rows / 2, src.cols / 2),50, Scalar(0, 200, 200), 2, LINE_AA);


	// »­ÎÄ±¾ putText
	// InputOutputArray img
	// const String& text
	// Point org,
	// int fontFace
	// double fontScale
	// Scalar color,
	// int thickness = 1
	// int lineType = LINE_8,
	// bool bottomLeftOrigin = false
	//putText(src,"Hello OpenCV",Point(20,100),FONT_HERSHEY_COMPLEX_SMALL,1.0, Scalar(200, 0, 200), 1, LINE_AA);

	// Ìî³ä fillPoly
	// Mat& img
	// const Point** pts,
	// const int* npts
	// int ncontours
	// const Scalar& color
	// int lineType = LINE_8
	// int shift = 0,
	// Point offset = Point()
	Point points[1][5];
	points[0][0] = Point(50,50);
	points[0][1] = Point(50,150);
	points[0][2] = Point(150,150);
	points[0][3] = Point(150,50);
	points[0][4] = Point(50,50);

	const Point* pts[1] = {points[0]};
	//const int npts[] = {5};
	int npts = 5;
	fillPoly(src, pts, &npts,1, Scalar(200, 200, 0));
	imshow("src",src);


end:
	waitKey(0);
	return 0;
}
*/