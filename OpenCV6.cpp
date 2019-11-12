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
	Mat src = imread("C:/Users/ubt/Desktop/dali.png");
	if (!src.data)
	{
		cout << "src read error!" << endl;
		return -1;
	}

	imshow("src",src);

	//InputArray src    输入
	//OutputArray dst   输出
	//int op            操作的类型CV_MOP_XXX
	//InputArray kernel 核
	Mat des;
	//Mat kernel = getStructuringElement(MORPH_RECT,Size(35,35));
	// morphologyEx(src,des,CV_MOP_CLOSE, kernel);
	//morphologyEx(src,des,CV_MOP_CLOSE, kernel);
	//morphologyEx(src,des, CV_MOP_TOPHAT, kernel);
	//morphologyEx(src,des, CV_MOP_BLACKHAT, kernel);

	//pyrUp(src,des,Size(src.cols<<1,src.rows<<1));
	pyrDown(src,des,Size(src.cols>>1,src.rows>>1));

	imshow("des", des);

	waitKey(0);
	return 0;
}
*/