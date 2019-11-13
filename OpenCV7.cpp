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

	// 提取轮廓值思路
	// 1.高斯降噪（图片平滑）
	// 2.灰度（提高计算效率）
	// 3.Sobel梯度计算获取轮廓值（x,y）方向
	// 4.因为Sobel算子中含有负值，所以需要将结果进行绝对值操作
	// 5.将横向和纵向的两个图合并
	Mat gaussian;
	GaussianBlur(src,gaussian,Size(3,3),0);

	Mat gray;
	cvtColor(src,gray,COLOR_BGR2GRAY);

	//Mat sobel_x, sobel_y;
	// 这里注意gray的深度为0，里面会进行一些列的+-*/操作，所以精度必须比原图的精度高
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