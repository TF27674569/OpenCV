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
	//Mat src = imread("C:/Users/ubt/Desktop/image1.png");
	Mat src = imread("C:/Users/ubt/Desktop/errod.png");

	if (!src.data)
	{
		cout << "src read error" << endl;
		return -1;
	}

	// ����һ����ԭͼ��Сһ����ͼ������ȫ��ͨ����ֵ��0���
	//Mat des = Mat::zeros(src.size(),src.type());
	//// ���� ��Ҫ����һ������ͨ����ֵ����0��ʼ��һ�е�һ��Ȣ������һ�к����һ����ֵ�����Դӵڶ��еڶ������������ڶ��еĵ����ڶ�����
	//int cols = (src.cols-1)*src.channels();
	//int rows = src.rows-1;
	//int offsetx = src.channels();

	//for (int i = 1; i < rows; i++)
	//{
	//	// ��һ��
	//	uchar* preLine = src.ptr<uchar>(i - 1);
	//	// ��ǰ��
	//	uchar* curLine = src.ptr<uchar>(i);
	//	// ��һ��
	//	uchar* nextLine = src.ptr<uchar>(i + 1);

	//	//��Ҫ����ͼƬ
	//	uchar* desLine = des.ptr<uchar>(i);

	//	// �����������ÿ��ͨ�������ص���ܺ���rgb����ֵ���ܵ����Ķ��������ص㸳ֵ��ֻ�ܶ�����ɫͨ����ֵ������ģ��
	//	for (int j = offsetx; j < cols; j++)
	//	{
	//		// ��ʼ��ģ
	//		desLine[j] = saturate_cast<uchar>( 5 * curLine[j] - (preLine[j] + curLine[j - offsetx] + curLine[j + offsetx] + nextLine[j]));
	//	}
	//}
	
	Mat dest;

	// InputArray src ����
	// OutputArray dst ���
	// int ddepth ���
	// InputArray kernel ��ģ�ĺˣ�Ҳ�������ǵĺ��ľ���
	// Point anchor = Point(-1, -1) Ĭ�Ͻ����������
	// double delta = 0
	// int borderType = BORDER_DEFAULT
	//Mat kernel = (Mat_<char>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	//filter2D(src,dest,src.depth(),kernel);

	//cout << src.depth() << endl;
	imshow("src",src);
	//InputArray src �����Mat
	//OutputArray dst �����Mat
	//Size ksize ��ģ�������ĺ˾���
	//Point anchor = Point(-1, -1) ���λ�ã������ʾΪ�˵����ģ�
	// blur(src,dest,Size(21,21));

	//InputArray src    ����
	//OutputArray dst   ���
	//int ksize         ��ΪҪ��ȡ�м�ֵ�����Ա��봫����
	//medianBlur(src,dest,5);

	//InputArray src       ����
	//OutputArray dst      ���
	//int d                ��ʾ�ڹ��˹�����ÿ�����������ֱ����Χ��������ֵ�Ƿ�������������ӵ��������sigmaSpace�����ֵ��
	//double sigmaColor    ��ɫ�ռ��������sigmaֵ�����������ֵ�´󣬱�����������������Խ������ɫ�ᱻ��ϵ�һ�𣬲����ϴ�İ������ɫ����
	//double sigmaSpace    ����ռ����˲�����sigmaֵ�������ֵ�ϴ�����ζ��ԽԶ�����ؽ��໥Ӱ�죬�Ӷ�ʹ������������㹻���Ƶ���ɫ��ȡ��ͬ����ɫ����d>0ʱ��dָ���������С����sigmaSpace�޹أ�����d������sigmaSpace.
	//bilateralFilter(src,dest, 15, 100, 5);//��������ֵ�ǣ�����ֵ��һ��ȡ����������


	//int shape   ��״(һ�㶼�Ǿ���)
	//Size ksize  �˾��� 
	Mat kernel = getStructuringElement(MORPH_RECT,Size(30,30));// ������һ��15x15��������
	//InputArray src     ����
	//OutputArray dst    ���
	//InputArray kernel  ��
	erode(src,dest, kernel);// ȡ��Сֵ��ɫ����Ŵ󣬰�ɫ������С


	dilate(src,dest, kernel);// ȡ���ֵ��ɫ����Ŵ󣬺�ɫ������С

	imshow("des", dest);
	waitKey(0);
	return 0;
}
*/