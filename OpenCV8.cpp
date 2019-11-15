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

	// 1.����Canny������Ե
	//Mat canny;
	//Canny(src,canny,40,100);
	//imshow("canny",canny);

	// 2.����ֱ�߼��
	//vector<Vec4f> lines;
	//InputArray image    ����ͼ
	//OutputArray lines   �õ�����
	//double rho          ���ص�ɨ���϶��ɨ��ʱ����������֮�����������
	//double theta        ����r=x*cos��+y*sin������Ƕ�ÿ�����ӵ�ֵ
	//int threshold       ����ֵ������ֵ�������threshold����Ϊ��һ���㣨��������㼴ʹ�����ϣ�Ҳ��ȥ����
	//double minLineLength = 0   ����������Ҫ�������ٸ��㣨�������ֵ���Ͳ���Ϊ���ߣ�
	//double maxLineGap = 0      Canny ֮�����������м���ܻ��жϿ��㣬�������Ͽ��ĵ���maxLineGap֮�ڣ�Ҳ����Ϊ�������ߵ�һ����
	//HoughLinesP(canny, lines,1,CV_PI/180,170,30,70);

	//for (int i = 0; i < lines.size(); i++)
	//{
	//	Vec4f pline = lines[i];

	//	line(src, Point(pline[0], pline[1]), Point(pline[2], pline[3]),Scalar(0,0,255),4);
	//}

	//3.����Բ���
	vector<Vec3f> circes;
	//InputArray image           ���ͼ
	//OutputArray circles        �õ���Բ��Բ�ĺͰ뾶��
	//int method                 Բֻ֧��HOUGH_GRADIENT
	//double dp                  Ϊ��һ�׶���ʹ�õĻ���ռ�ķֱ��ʣ�dp=1ʱ��ʾ����ռ�������ͼ��ռ�Ĵ�Сһ�£�dp=2ʱ����ռ�������ͼ��ռ��һ�룬�Դ�����
	//double minDist             Բ��֮�����С���룬�����⵽������Բ��֮�����С�ڸ�ֵ������Ϊ������ͬһ��Բ��
	//double param1 = 100        ͶƱ�ۼӽ���������ٲ�����Բ���ж��ٸ��㣩��ʾ���ݸ�canny��Ե������ӵĸ���ֵ��������ֵΪ����ֵ��һ�롣
	//double param2 = 100        ����ֵ  ���ĵ��ۼ�����ֵ �C ��ѡԲ�ġ���ԽС�Ļ����Ϳ��Լ�⵽������������ڵ�Բ������Խ��Ļ�����ͨ������Բ�͸��ӽӽ�������Բ���ˡ�
	//int minRadius = 0          ��С�İ뾶
	//int maxRadius = 0          ���İ뾶
	//HoughCircles(canny, circes, HOUGH_GRADIENT,1, src.rows / 5, 150, 70, 0, 0);

	//for (int i = 0; i < circes.size(); i++)
	//{
	//	Vec3f pcircle = circes[i];

	//	circle(src,Point(pcircle[0],pcircle[1]),pcircle[2],Scalar(0,0,255),3);
	//}


	Mat des;
	Mat mat_x(src.size(),CV_32FC1), mat_y(src.size(), CV_32FC1);



	// �˴���ͼ��������ҷ�ת  �㣨x��y����ɣ�src.cols-x,y��,Ҳ������ߵ����ص��ֵ���ұ����ص��ֵȥ���
	// ����mat_x��������xֵ��Ӧ�ĵ���ԭͼ�е��λ�ã�����������ֵ��mat_x��mat_yֻ�Ǳ�ʾ��һ������
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			// ��ǰ��x = ԭ���е����һ����λ�ò�������ֵ��
			mat_x.at<float>(i, j) = static_cast<float>(src.cols -j);
			// ��ǰ��y  = ԭ��y��λ��
			mat_y.at<float>(i, j) = i;
		}
	}


	//InputArray src    ����
	//OutputArray dst   ���
	//InputArray map1   ��ӳ����x��Ӧԭͼ��λ��
	//InputArray map2   ��ӳ����y��Ӧԭͼ��λ��
	//int interpolation �˲���ʽ������ѡ�������˲�
	remap(src, des, mat_x,mat_y, INTER_LINEAR);

	imshow("result", des);
	
	waitKey(0);
	return 0;
}
*/