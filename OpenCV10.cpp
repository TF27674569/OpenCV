#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;

/*
int main()
{
	Mat img1 = imread("C:/Users/ubt/Desktop/test.png");
	Mat img2 = imread("C:/Users/ubt/Desktop/test_.png");
	Mat img3 = imread("C:/Users/ubt/Desktop/2_04.png");

	// RGB -> HSV , ���� HS ֱ��ͼ 
	// ��ΪRGB��һЩ������صĲ�������Ӧ��Ӱ�����ƶȣ���������ʹ��HSV�ĸ�ʽ�����Ҷ�����V����������ͳ�ƣ�ֻ�Ƚ�ɫ��ͱ��Ͷ�
	Mat hs_1, hs_2, hs_3;
	cvtColor(img1, hs_1,COLOR_BGR2HSV);
	cvtColor(img2, hs_2,COLOR_BGR2HSV);
	cvtColor(img3, hs_3,COLOR_BGR2HSV);


	// ���� ���ǵ���mat ������������
	MatND hist1, hist2, hist3;

	int channls[2] = {0,1}; 
	int h_bins = 50;
	int s_bins = 50;
	int hist_size[] = { h_bins, s_bins };
	float h_rangs[] = { 0,180 };// 0~360 cvtColor�ڽ��й�ʽת��ʱ��Ҫ�Ƚ��й�һ������ӳ��ɣ�0-360���ϵı������ĵ���ֵ���������ڣ�8UC��ͨ�����ֵֻ����255���޷�ӳ�䵽360�����ԣ�����������ڼ���ʱ��ѹ�����ˣ�0-180��
	float s_rangs[] = { 0,256 };// ����256 ����255������ֵ���ᱻͳ�Ƶ�
	const float* rangs[] = { h_rangs, s_rangs };

	// ֱ��ͼͳ�Ƽ���
	// hs_1 �� ��Ҫͳ�Ƶ�ͼƬ��mat
	// 1�� �����м���ͼ
	// channls����Ӧ�ڼ�ͨ�� H(0) S(1)����ͨ��
	// Mat()��������ģ�ľ������ﲻ��ģ
	// hist1��ͳ�ƺ��Mat��������˫ͨ����mat
	// 2 �����������ֱ��ͼ��ά����һ��ͼ�м���ֱ��ͼ
	// hist_size����ÿһά��ֱ��ͼ�ĸ������򵥰�ֱ��ͼ����һ��һ���������Ļ�������ÿһά�������ĸ���(�ֳɶ��ٷݣ�0-255����10�ݣ�ÿ�ݾ���25.5)��
	// rangs��ͳ�Ƶķ�Χ,H(0-180),S(0-255)
	calcHist(&hs_1,1, channls,Mat(), hist1, 2,hist_size, rangs);
	calcHist(&hs_2,1, channls,Mat(), hist2, 2,hist_size, rangs);
	calcHist(&hs_2,1, channls,Mat(), hist2, 2,hist_size, rangs);

	// ��һ�� ���룬�������Сֵ�����ֵ��type
	normalize(hist1, hist1,0,1,CV_MINMAX);
	normalize(hist2, hist2,0,1,CV_MINMAX);
	normalize(hist3, hist3,0,1,CV_MINMAX);

	// ֱ��ͼ�Ƚ�
	double val1 = compareHist(hist1, hist1, CV_COMP_CORREL);
	double val2 = compareHist(hist1, hist2, CV_COMP_CORREL);
	//double val3 = compareHist(hist1, hist3, CV_COMP_CORREL);


	cout << val1 << endl;
	cout << val2 << endl;
	//cout << val3 << endl;

	waitKey(0);
	return 0;
}



int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/test_.png");

	Mat hsv;
	cvtColor(src, hsv, COLOR_BGR2HSV);

	vector<Mat> hsv_s;
	// ������ͨ��
	split(hsv, hsv_s);
	// hͨ��
	Mat hueImage = hsv_s[0];

	Mat hist;
	const int hist_size[] = {2};
	float hue_range[] = { 0,180 };
	const float* ranges[] = { hue_range };

	// ֱ��ͳ��
	calcHist(&hueImage,1, 0,Mat(), hist,1, hist_size, ranges);
	// ��һ��
	normalize(hist, hist, 0, 255, NORM_MINMAX);

	Mat backPro;
	calcBackProject(&hueImage,1,0, hist, backPro, ranges);

	imshow("backPro", backPro);


	waitKey(0);
	return 0;
}
*/


int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/qd.jpg");
	Mat tag = imread("C:/Users/ubt/Desktop/tag.jpg");

	// ������ֵ������һ���� src.rows-tag.rows
	// ����src.cols-tag.cols+1 
	// �����ֵ �϶�����С��CV_32FC1
	Mat out_arr(src.rows-tag.rows+1, src.cols-tag.cols+1,CV_32FC1);
	// TM_SQDIFF ƽ����ƥ��
	matchTemplate(src, tag, out_arr, TM_SQDIFF);
	// ����������minVal �ں�����ͨ��ָ�븳ֵ����������ֵ��
	double minVal = 0;
	double maxVal = 0;
	Point minLoc;
	Point maxLoc;
	// Ѱ����Сֵ�����ֵ��λ��
	minMaxLoc(out_arr, &minVal, &maxVal, &minLoc, &maxLoc);

	// TM_SQDIFF ���ƥ��ֵΪ0
	cout << "minVal:" << minVal << endl;
	cout << "maxVal:"<< maxVal << endl;
	
	rectangle(src, minLoc, Point(minLoc.x + tag.cols, minLoc.y + tag.rows), Scalar(0, 0, 255), 2, 8);


	imshow("src",src);
	waitKey(0);
	return 0;
}