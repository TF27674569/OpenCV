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

	// 1.����Canny������Ե
	Mat canny;
	Canny(src,canny,40,120);
	imshow("canny",canny);

	// 2.����ֱ�߼��
	vector<Vec4f> lines;
	//InputArray image    ����ͼ
	//OutputArray lines   �õ�����
	//double rho          ���ص�ɨ���϶��ɨ��ʱ����������֮�����������
	//double theta        ����r=x*cos��+y*sin������Ƕ�ÿ�����ӵ�ֵ
	//int threshold       ����ֵ������ֵ�������threshold����Ϊ��һ���㣨��������㼴ʹ�����ϣ�Ҳ��ȥ����
	//double minLineLength = 0   ����������Ҫ�������ٸ��㣨�������ֵ���Ͳ���Ϊ���ߣ�
	//double maxLineGap = 0      Canny ֮�����������м���ܻ��жϿ��㣬�������Ͽ��ĵ���maxLineGap֮�ڣ�Ҳ����Ϊ�������ߵ�һ����
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
