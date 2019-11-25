#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;

/*
int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/bank.jpg");

	// 1.图像转灰度
	Mat gray;
	cvtColor(src,gray,COLOR_BGR2GRAY);
	// 2.高斯降噪
	GaussianBlur(gray, gray,Size(5,5),0);
	// 3.边缘检测
	Canny(gray,gray,50,150);
	// 4.提取轮廓值    轮廓值 = {轮廓1，轮廓2, ...}   轮廓1={point1，point2, ...}
	// 轮廓值是以一组数据点存储在一个集合里面，所有的集合组成一个轮廓集合findContours，查出的就是一组轮廓的集合
	vector<vector<Point>> contours;// 所有轮廓的集合
	// mode（推荐文章里面有详细介绍）:CV_RETR_EXTERNAL检测外围轮廓 CV_RETR_LIST    检测所有的轮廓 
	// method推荐文章里面有详细介绍）:定义轮廓的近似方法，即轮廓如何呈现的方法
	// CV_CHAIN_APPROX_SIMPLE  仅保存轮廓的拐点信息，把所有轮廓拐点处的点保存入contours 向量内，拐点与拐点之间直线段上的信息点不予保留，压缩水平方向，垂直方向，对角线方向的元素，值保留该方向的重点坐标，如果一个矩形轮廓只需4个点来保存轮廓信息
	//findContours(gray, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE); //外部轮廓
	findContours(gray, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);//所有轮廓


	imshow("canny", gray);

	// 5.绘制轮廓 drawContours
	Mat des(src.size(),CV_8UC3);// 用红色画，选CV_8UC3

	// 轮廓区域
	Rect target;
	for (int i = 0; i < contours.size(); i++)
	{
		// InputOutputArray image 画在哪个mat上
		// InputArrayOfArrays contours 需要画的轮廓
		// int contourIdx 指定绘制的编号，如果未负数则绘制所有轮廓
		// const Scalar& color 颜色
		// int thickness = 1 线的粗细，如果为负数则全部填充
		drawContours(des, contours,i,Scalar(0,0,255),2);

		// 获取轮廓
		Rect rect = boundingRect(contours[i]);
		// 如果宽高都大于屏幕的一半，则认为是最大轮廓
		if (rect.width > src.cols / 2 && rect.height > src.rows / 2) {
			target = rect;
			// 我这里画在原图上 圈出卡片区域
			rectangle(src, target,Scalar(0,255,0),3);
		}

	}
	imshow("des", des);
	imshow("src", src);
	
	// 6.裁剪轮廓
	Mat clip = src(target);
	imshow("clip", clip);


	waitKey(0);
	return 0;
}


int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/test.txt");
	Mat gray;
	/// 转成灰度图并进行模糊降噪
	cvtColor(src, gray, CV_BGR2GRAY);
	blur(gray, gray, Size(3, 3));
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));


	/// 对图像进行二值化
	threshold(gray, gray, 100, 255, THRESH_BINARY);
	vector<vector<Point>> contours;// 所有轮廓的集合
	findContours(gray, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE); //外部轮廓

	/// 对每个轮廓计算其凸包
	vector<vector<Point>>  hull(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		convexHull(Mat(contours[i]), hull[i]);
	}


	// 绘出轮廓及其凸包
	Mat drawing = Mat::zeros(gray.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		drawContours(drawing, contours, i, Scalar(0, 0, 255), 2);
		drawContours(drawing, hull, i, Scalar(0, 255, 0), 2);
	}

	imshow("src",src);
	imshow("drawing", drawing);

	waitKey(0);
	return 0;
}
*/