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

	// 1.ͼ��ת�Ҷ�
	Mat gray;
	cvtColor(src,gray,COLOR_BGR2GRAY);
	// 2.��˹����
	GaussianBlur(gray, gray,Size(5,5),0);
	// 3.��Ե���
	Canny(gray,gray,50,150);
	// 4.��ȡ����ֵ    ����ֵ = {����1������2, ...}   ����1={point1��point2, ...}
	// ����ֵ����һ�����ݵ�洢��һ���������棬���еļ������һ����������findContours������ľ���һ�������ļ���
	vector<vector<Point>> contours;// ���������ļ���
	// mode���Ƽ�������������ϸ���ܣ�:CV_RETR_EXTERNAL�����Χ���� CV_RETR_LIST    ������е����� 
	// method�Ƽ�������������ϸ���ܣ�:���������Ľ��Ʒ�������������γ��ֵķ���
	// CV_CHAIN_APPROX_SIMPLE  �����������Ĺյ���Ϣ�������������յ㴦�ĵ㱣����contours �����ڣ��յ���յ�֮��ֱ�߶��ϵ���Ϣ�㲻�豣����ѹ��ˮƽ���򣬴�ֱ���򣬶Խ��߷����Ԫ�أ�ֵ�����÷�����ص����꣬���һ����������ֻ��4����������������Ϣ
	//findContours(gray, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE); //�ⲿ����
	findContours(gray, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);//��������


	imshow("canny", gray);

	// 5.�������� drawContours
	Mat des(src.size(),CV_8UC3);// �ú�ɫ����ѡCV_8UC3

	// ��������
	Rect target;
	for (int i = 0; i < contours.size(); i++)
	{
		// InputOutputArray image �����ĸ�mat��
		// InputArrayOfArrays contours ��Ҫ��������
		// int contourIdx ָ�����Ƶı�ţ����δ�����������������
		// const Scalar& color ��ɫ
		// int thickness = 1 �ߵĴ�ϸ�����Ϊ������ȫ�����
		drawContours(des, contours,i,Scalar(0,0,255),2);

		// ��ȡ����
		Rect rect = boundingRect(contours[i]);
		// �����߶�������Ļ��һ�룬����Ϊ���������
		if (rect.width > src.cols / 2 && rect.height > src.rows / 2) {
			target = rect;
			// �����ﻭ��ԭͼ�� Ȧ����Ƭ����
			rectangle(src, target,Scalar(0,255,0),3);
		}

	}
	imshow("des", des);
	imshow("src", src);
	
	// 6.�ü�����
	Mat clip = src(target);
	imshow("clip", clip);


	waitKey(0);
	return 0;
}


int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/test.txt");
	Mat gray;
	/// ת�ɻҶ�ͼ������ģ������
	cvtColor(src, gray, CV_BGR2GRAY);
	blur(gray, gray, Size(3, 3));
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));


	/// ��ͼ����ж�ֵ��
	threshold(gray, gray, 100, 255, THRESH_BINARY);
	vector<vector<Point>> contours;// ���������ļ���
	findContours(gray, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE); //�ⲿ����

	/// ��ÿ������������͹��
	vector<vector<Point>>  hull(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		convexHull(Mat(contours[i]), hull[i]);
	}


	// �����������͹��
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