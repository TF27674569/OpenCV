#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;



int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/yhk.jpg");

	if (!src.data)
	{
		cout << "imread error" << endl;
		return -1;
	}

	// ��ȡ����ֵ˼·
	// 1.��˹���루ͼƬƽ����
	// 2.�Ҷȣ���߼���Ч�ʣ�
	// 3.Sobel�ݶȼ����ȡ����ֵ��x,y������
	// 4.��ΪSobel�����к��и�ֵ��������Ҫ��������о���ֵ����
	// 5.����������������ͼ�ϲ�
	Mat gaussian;
	GaussianBlur(src,gaussian,Size(3,3),0);

	Mat gray;
	cvtColor(src,gray,COLOR_BGR2GRAY);

	//Mat sobel_x, sobel_y;
	// ����ע��gray�����Ϊ0����������һЩ�е�+-*/���������Ծ��ȱ����ԭͼ�ľ��ȸ�
	//Scharr(gray, sobel_x,CV_16S,1,0);
	//Scharr(gray, sobel_y,CV_16S,0, 1);

	//convertScaleAbs(sobel_x, sobel_x);
	//convertScaleAbs(sobel_y, sobel_y);

	//Mat sobel;
	//addWeighted(sobel_x,1, sobel_y,1,0, sobel);

	//Mat laplac;
	//Laplacian(gray, laplac, CV_16S,3);
	//convertScaleAbs(laplac, laplac);


	Mat canny;

	Canny(src,canny,50,150);
	imshow("canny", canny);

	waitKey(0);
	return 0;
}