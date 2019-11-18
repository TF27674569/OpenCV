#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;

/*
int main()
{
	//Mat src = imread("C:/Users/ubt/Desktop/2_04.png");
	//Mat src = imread("C:/Users/ubt/Desktop/gl.png");
	Mat src = imread("C:/Users/ubt/Desktop/2_05.jpg");

	if (!src.data)
	{
		cout << "imread error" << endl;
		return -1;
	}

	imshow("src",src);
	
	//Mat gray;
	//cvtColor(src,gray,COLOR_BGR2GRAY);

	//Mat des;
	//equalizeHist(gray, gray);


	// 对BGR各个通道的颜色进行直方均衡
	//vector<Mat> channls;
	//split(src, channls);

	//equalizeHist(channls[0], channls[0]);
	//equalizeHist(channls[1], channls[1]);
	//equalizeHist(channls[2], channls[2]);

	//Mat des;
	//merge(channls, des);


	// 对图像的Y分量进行直方均衡
	//Mat ycbcr;
	//cvtColor(src, ycbcr,COLOR_BGR2YCrCb);

	//vector<Mat> channls;
	//split(ycbcr, channls);

	//equalizeHist(channls[0], channls[0]);
	//Mat des;
	//merge(channls, des);

	//cvtColor(des, des, COLOR_YCrCb2BGR);



	// 直方图统计提取

	// 分离三通道
	vector<Mat> brg_s;
	split(src, brg_s);

	//images: 输入的图像或数组，它们的深度必须为CV_8U, CV_16U或CV_32F中的一类，尺寸必须相同。
	//nimages : 输入数组个数，也就是第一个参数中存放了几张图像，有几个原数组。
	//channels : 需要统计的通道dim，第几通道
	//mask : 掩模,这里不掩模，Mat传一个空对象
	//hist : 输出的目标直方图，一个二维数组
	//dims :需要统计的通道个数
	//histSize : 等级的个数 单通道 0-255
	//ranges : 数据的范围  0-255
	//uniform : 是否对得到的图片进行归一化处理
	//accumulate : 在多个图像时，是否累计计算像素值的个数 false
		
	int histSize = 256;
	const float range[] = { 0,256 };
	const float* ranges = { range };
	Mat hist_b, hist_g, hist_r;
	// 对b通道进行直方统计，统计结果放在了hist_b里面也就是0-256区间值的分布情况，存的值最小为0，也就是整张图上没有一个蓝色的点，最大时突变的宽*高，全部都是蓝色的点
	calcHist(&brg_s[0], 1, 0, Mat(), hist_b, 1,&histSize,&ranges);
	calcHist(&brg_s[1], 1, 0, Mat(), hist_g, 1, &histSize, &ranges);
	calcHist(&brg_s[2], 1, 0, Mat(), hist_r, 1, &histSize, &ranges);



	int hist_h = 400;
	// 归一化
	//InputArray src  输入的mat
	//InputOutputArray dst  归一化后的mat
	//double alpha = 1 最小值
	//double beta = 0  最大值 这里限定了400
	//int norm_type = NORM_L2 NORM_MINMAX最小值最大值类型
	normalize(hist_b, hist_b, 0, hist_h, NORM_MINMAX);
	normalize(hist_g, hist_g, 0, hist_h, NORM_MINMAX);
	normalize(hist_r, hist_r, 0, hist_h, NORM_MINMAX);



	int hist_w = 512; // 256*2
	int bin_w = 2;// 画笔的大小
	// 画到一张mat上面 高400 宽每个点取两个像素宽（画笔宽为2）
	Mat histImage(hist_h, hist_w, CV_8SC4);

	for (int i = 1; i < histSize; i++)// x=0 没必要画
	{
		// 相邻的两个点用一个线条来画
		line(histImage,Point((i - 1) * bin_w, hist_h - hist_b.at<float>(i - 1)),Point(i * bin_w, hist_h - hist_b.at<float>(i)),Scalar(255,0,0), bin_w);
		line(histImage,Point((i - 1) * bin_w, hist_h - hist_g.at<float>(i - 1)),Point(i * bin_w, hist_h - hist_g.at<float>(i)),Scalar(0,255,0), bin_w);
		line(histImage,Point((i - 1) * bin_w, hist_h - hist_r.at<float>(i - 1)),Point(i * bin_w, hist_h - hist_r.at<float>(i)),Scalar(0,0,255), bin_w);
	}

	// 最后得到b g r各通道的曲线分布图
	imshow("hist", histImage);


	waitKey(0);
	return 0;
}
*/