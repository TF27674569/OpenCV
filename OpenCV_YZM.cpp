#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;

/*

// opencv ��֤�뽵��
void main()
{

	Mat src = imread("C:/Users/ubt/Desktop/yam.png");
	if (!src.data)
	{
		cout << "src read error!" << endl;
		return ;
	}

	imshow("src", src);

	// 1.ת�Ҷ�ͼ
	Mat gray_res;
	cvtColor(src, gray_res,COLOR_BGR2GRAY);
	imshow("gray_res", gray_res);

	// 2.��ֵ��ת�ڰ�
	Mat des_w_b;
	//InputArray src   ����
	//OutputArray dst  ���
	// double thresh   �����һ����ֵ
	// double maxval   ���ֵ�����ֵ��0-255 ����Ϊ255��
	// int type  ���� THRESH_BINARY  ����thresh����Ϊ255 С����Ϊ 0 
	//                THRESH_BINARY_INV     ����thresh����Ϊ0 С����Ϊ 255 
	//                THRESH_TRUNC         ����thresh���ֱ���Ϊthresh��С�ڲ��ֱ���ԭ��  
	//                THRESH_TOZERO         С��thresh���ֱ���Ϊ0�����ڲ��ֱ���ԭ��  
	//                THRESH_TOZERO_INV      ����thresh���ֱ���Ϊ0��С�ڲ��ֱ��ֲ��� 

	// ��Ϊ��ɫͼ����лҶ�֮�����ڻҶȵ���ǳ���⣬������ȡ��ͼ��ķ�ֵ��Ȼ��ʹ��THRESH_BINARY_INV����ȡ�ؼ���Ϣ�͸��ŵ��ڣ����ಿ�ֻ��Ǻڵ�
	threshold(~gray_res, des_w_b, 50,255, THRESH_BINARY_INV);
	imshow("des_w_b", des_w_b);

	// 3.ȥ�����ŵ㣨�����Ǻ�ɫ�ĸ��ŵ㣬�Ǿ��ȸ�ʴ�����ͣ�ѡ�ñղ���CV_MOP_CLOSE��
	Mat des;
	Mat kernel = getStructuringElement(MORPH_RECT,Size(5,5));
	morphologyEx(des_w_b,des, CV_MOP_CLOSE, kernel);
	imshow("des", des);

	// ��ʱ�Ѿ��Ǹɾ�����֤��ͼƬ�������ȶԿ�Ϳ��Եõ���֤��
	//...
	waitKey(0);

}

*/
