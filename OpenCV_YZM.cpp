#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;

/*

// opencv 验证码降噪
void main()
{

	Mat src = imread("C:/Users/ubt/Desktop/yam.png");
	if (!src.data)
	{
		cout << "src read error!" << endl;
		return ;
	}

	imshow("src", src);

	// 1.转灰度图
	Mat gray_res;
	cvtColor(src, gray_res,COLOR_BGR2GRAY);
	imshow("gray_res", gray_res);

	// 2.二值化转黑白
	Mat des_w_b;
	//InputArray src   输入
	//OutputArray dst  输出
	// double thresh   定义的一个阈值
	// double maxval   这个值的最大值（0-255 所以为255）
	// int type  类型 THRESH_BINARY  大于thresh被置为255 小于置为 0 
	//                THRESH_BINARY_INV     大于thresh被置为0 小于置为 255 
	//                THRESH_TRUNC         大于thresh部分被置为thresh，小于部分保持原样  
	//                THRESH_TOZERO         小于thresh部分被置为0，大于部分保持原样  
	//                THRESH_TOZERO_INV      大于thresh部分被置为0，小于部分保持不变 

	// 因为彩色图像进行灰度之后会存在灰度的深浅问题，我这里取的图像的反值，然后使用THRESH_BINARY_INV来获取关键信息和干扰点变黑，其余部分还是黑的
	threshold(~gray_res, des_w_b, 50,255, THRESH_BINARY_INV);
	imshow("des_w_b", des_w_b);

	// 3.去除干扰点（这里是黑色的干扰点，那就先腐蚀后膨胀，选用闭操作CV_MOP_CLOSE）
	Mat des;
	Mat kernel = getStructuringElement(MORPH_RECT,Size(5,5));
	morphologyEx(des_w_b,des, CV_MOP_CLOSE, kernel);
	imshow("des", des);

	// 此时已经是干净的验证码图片，经过比对库就可以得到验证码
	//...
	waitKey(0);

}

*/
