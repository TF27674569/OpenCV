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

	// RGB -> HSV , 计算 HS 直方图 
	// 因为RGB中一些亮度相关的参数，不应该影响相似度，所有我们使用HSV的格式，并且对亮度V分量不参与统计，只比较色相和饱和度
	Mat hs_1, hs_2, hs_3;
	cvtColor(img1, hs_1,COLOR_BGR2HSV);
	cvtColor(img2, hs_2,COLOR_BGR2HSV);
	cvtColor(img3, hs_3,COLOR_BGR2HSV);


	// 复数 便是单个mat 存有两个分量
	MatND hist1, hist2, hist3;

	int channls[2] = {0,1}; 
	int h_bins = 50;
	int s_bins = 50;
	int hist_size[] = { h_bins, s_bins };
	float h_rangs[] = { 0,180 };// 0~360 cvtColor在进行公式转换时需要先进行归一化，在映射成（0-360）上的比例所的到的值，但是由于，8UC的通道最大值只能是255，无法映射到360，所以，这里的区间在计算时就压缩到了（0-180）
	float s_rangs[] = { 0,256 };// 必须256 否则255的像素值不会被统计到
	const float* rangs[] = { h_rangs, s_rangs };

	// 直方图统计计算
	// hs_1 ： 需要统计的图片的mat
	// 1： 里面有几张图
	// channls：对应第几通道 H(0) S(1)两个通道
	// Mat()：进行掩模的矩阵，这里不掩模
	// hist1：统计后的Mat，这里是双通道的mat
	// 2 ：计算出来的直方图的维数，一张图有几种直方图
	// hist_size：在每一维上直方图的个数。简单把直方图看作一个一个的竖条的话，就是每一维上竖条的个数(分成多少份（0-255）分10份，每份就是25.5)。
	// rangs：统计的范围,H(0-180),S(0-255)
	calcHist(&hs_1,1, channls,Mat(), hist1, 2,hist_size, rangs);
	calcHist(&hs_2,1, channls,Mat(), hist2, 2,hist_size, rangs);
	calcHist(&hs_2,1, channls,Mat(), hist2, 2,hist_size, rangs);

	// 归一化 输入，输出，最小值，最大值，type
	normalize(hist1, hist1,0,1,CV_MINMAX);
	normalize(hist2, hist2,0,1,CV_MINMAX);
	normalize(hist3, hist3,0,1,CV_MINMAX);

	// 直方图比较
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
	// 分离三通道
	split(hsv, hsv_s);
	// h通道
	Mat hueImage = hsv_s[0];

	Mat hist;
	const int hist_size[] = {2};
	float hue_range[] = { 0,180 };
	const float* ranges[] = { hue_range };

	// 直方统计
	calcHist(&hueImage,1, 0,Mat(), hist,1, hist_size, ranges);
	// 归一化
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

	// 遍历的值横向冲第一个到 src.rows-tag.rows
	// 纵向src.cols-tag.cols+1 
	// 计算的值 肯定含有小数CV_32FC1
	Mat out_arr(src.rows-tag.rows+1, src.cols-tag.cols+1,CV_32FC1);
	// TM_SQDIFF 平方差匹配
	matchTemplate(src, tag, out_arr, TM_SQDIFF);
	// 传出参数：minVal 在函数中通过指针赋值，当做返回值用
	double minVal = 0;
	double maxVal = 0;
	Point minLoc;
	Point maxLoc;
	// 寻找最小值和最大值的位置
	minMaxLoc(out_arr, &minVal, &maxVal, &minLoc, &maxLoc);

	// TM_SQDIFF 最好匹配值为0
	cout << "minVal:" << minVal << endl;
	cout << "maxVal:"<< maxVal << endl;
	
	rectangle(src, minLoc, Point(minLoc.x + tag.cols, minLoc.y + tag.rows), Scalar(0, 0, 255), 2, 8);


	imshow("src",src);
	waitKey(0);
	return 0;
}