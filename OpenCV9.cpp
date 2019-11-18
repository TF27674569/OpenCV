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


	// ��BGR����ͨ������ɫ����ֱ������
	//vector<Mat> channls;
	//split(src, channls);

	//equalizeHist(channls[0], channls[0]);
	//equalizeHist(channls[1], channls[1]);
	//equalizeHist(channls[2], channls[2]);

	//Mat des;
	//merge(channls, des);


	// ��ͼ���Y��������ֱ������
	//Mat ycbcr;
	//cvtColor(src, ycbcr,COLOR_BGR2YCrCb);

	//vector<Mat> channls;
	//split(ycbcr, channls);

	//equalizeHist(channls[0], channls[0]);
	//Mat des;
	//merge(channls, des);

	//cvtColor(des, des, COLOR_YCrCb2BGR);



	// ֱ��ͼͳ����ȡ

	// ������ͨ��
	vector<Mat> brg_s;
	split(src, brg_s);

	//images: �����ͼ������飬���ǵ���ȱ���ΪCV_8U, CV_16U��CV_32F�е�һ�࣬�ߴ������ͬ��
	//nimages : �������������Ҳ���ǵ�һ�������д���˼���ͼ���м���ԭ���顣
	//channels : ��Ҫͳ�Ƶ�ͨ��dim���ڼ�ͨ��
	//mask : ��ģ,���ﲻ��ģ��Mat��һ���ն���
	//hist : �����Ŀ��ֱ��ͼ��һ����ά����
	//dims :��Ҫͳ�Ƶ�ͨ������
	//histSize : �ȼ��ĸ��� ��ͨ�� 0-255
	//ranges : ���ݵķ�Χ  0-255
	//uniform : �Ƿ�Եõ���ͼƬ���й�һ������
	//accumulate : �ڶ��ͼ��ʱ���Ƿ��ۼƼ�������ֵ�ĸ��� false
		
	int histSize = 256;
	const float range[] = { 0,256 };
	const float* ranges = { range };
	Mat hist_b, hist_g, hist_r;
	// ��bͨ������ֱ��ͳ�ƣ�ͳ�ƽ��������hist_b����Ҳ����0-256����ֵ�ķֲ���������ֵ��СΪ0��Ҳ��������ͼ��û��һ����ɫ�ĵ㣬���ʱͻ��Ŀ�*�ߣ�ȫ��������ɫ�ĵ�
	calcHist(&brg_s[0], 1, 0, Mat(), hist_b, 1,&histSize,&ranges);
	calcHist(&brg_s[1], 1, 0, Mat(), hist_g, 1, &histSize, &ranges);
	calcHist(&brg_s[2], 1, 0, Mat(), hist_r, 1, &histSize, &ranges);



	int hist_h = 400;
	// ��һ��
	//InputArray src  �����mat
	//InputOutputArray dst  ��һ�����mat
	//double alpha = 1 ��Сֵ
	//double beta = 0  ���ֵ �����޶���400
	//int norm_type = NORM_L2 NORM_MINMAX��Сֵ���ֵ����
	normalize(hist_b, hist_b, 0, hist_h, NORM_MINMAX);
	normalize(hist_g, hist_g, 0, hist_h, NORM_MINMAX);
	normalize(hist_r, hist_r, 0, hist_h, NORM_MINMAX);



	int hist_w = 512; // 256*2
	int bin_w = 2;// ���ʵĴ�С
	// ����һ��mat���� ��400 ��ÿ����ȡ�������ؿ����ʿ�Ϊ2��
	Mat histImage(hist_h, hist_w, CV_8SC4);

	for (int i = 1; i < histSize; i++)// x=0 û��Ҫ��
	{
		// ���ڵ���������һ����������
		line(histImage,Point((i - 1) * bin_w, hist_h - hist_b.at<float>(i - 1)),Point(i * bin_w, hist_h - hist_b.at<float>(i)),Scalar(255,0,0), bin_w);
		line(histImage,Point((i - 1) * bin_w, hist_h - hist_g.at<float>(i - 1)),Point(i * bin_w, hist_h - hist_g.at<float>(i)),Scalar(0,255,0), bin_w);
		line(histImage,Point((i - 1) * bin_w, hist_h - hist_r.at<float>(i - 1)),Point(i * bin_w, hist_h - hist_r.at<float>(i)),Scalar(0,0,255), bin_w);
	}

	// ���õ�b g r��ͨ�������߷ֲ�ͼ
	imshow("hist", histImage);


	waitKey(0);
	return 0;
}
*/