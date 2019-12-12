#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "zbar.h"

#pragma comment(lib,"opencv_world344d.lib")
#pragma comment(lib,"libzbar64-0.lib")

// 根据y = kx+b  求点x 对应的y值
#define LINT_Y(k,b,x) (((k)*(x))+b)


using namespace cv;
using namespace std;
using namespace zbar;

int main()
{
	//Mat src = imread("C:/Users/ubt/Desktop/opencv/qr_code1.png");
	//Mat src = imread("C:/Users/ubt/Desktop/opencv/qr1.jpg");
	Mat src = imread("C:/Users/ubt/Desktop/opencv/qr4.jpg");

	if (src.empty())
	{
		cout << "imread error" << endl;

		return -1;
	}

	imshow("原图", src);

	cout << "width:" << src.cols <<"   height:"<< src.rows << endl;

	// 中值滤波降噪，比高斯效率高
	Mat  blur_mat;
	blur(src, blur_mat,Size(5,5));

	// 灰度
	Mat gray;
	cvtColor(blur_mat, gray,COLOR_BGR2GRAY);

	// 二值化  自动阈值
	threshold(gray, gray,0,255,THRESH_BINARY|THRESH_OTSU);

	//imshow("gray", gray);

	// 腐蚀
	Mat erode_mat_min;
	Mat kernel_min = getStructuringElement(MORPH_RECT,Size(11, 11));
	erode(gray, erode_mat_min, kernel_min);

	Mat erode_mat_max;
	Mat kernel_max = getStructuringElement(MORPH_RECT, Size(15, 15));
	erode(gray, erode_mat_max, kernel_max);
	
	// 轮廓 得到白色的边界
	Mat contour_mat = erode_mat_min- erode_mat_max;
	//imshow("contour_mat", contour_mat);

	// 霍夫线检测
	vector<Vec4f> lines;
	HoughLinesP(contour_mat, lines, 1, CV_PI / 180, min(src.cols,src.rows)/3 , 20, 30);


	//画板 画线条
	Mat canvas = Mat::zeros(gray.size(), CV_8UC1);

	if (lines.size()==0)
	{
		cout << "line size is zero !!" << lines.size() << endl;

		//return -1;
	}

	cout << "line size" << lines.size() << endl;

	for (int i = 0; i < lines.size(); i++)
	{
		Vec4f pline = lines[i];
		// y = kx+b
		double k = (pline[3] - pline[1]) / (pline[2] - pline[0]);
		double b = pline[1] - k * pline[0];
		// 方程式求出后 x取一个负值   x再取一个比屏幕大的值  则线条超出屏幕
		Point2f pStart = Point2f(-1, LINT_Y(k,b,-1));

		Point2f pEnd = Point2f(canvas.cols, LINT_Y(k,b, canvas.cols));

		line(canvas, pStart, pEnd, Scalar::all(255), 1);

	}


	//imshow("canvas", canvas);

	//角点检测  
	vector<Point2f> corners;
	goodFeaturesToTrack(canvas, corners, 4, 0.1, 10);


	// 仿射变换的两个数组
	Point2f affine_target[4];
	Point2f affine_result[4];

	for (int i = 0; i < 4; i++)
	{
		affine_target[i] = corners[i];
		// 画出角点看一下
		//circle(src, affine_target[i],4,Scalar(0,0,255),10);

		// 仿射对应的位置
		if (corners[i].x<gray.cols>>1)
		{
			// 左边
			if (corners[i].y<gray.cols >> 1)
			{
				// 上
				affine_result[i] = Point2f(0, 0);
			}
			else
			{
				// 下
				affine_result[i] = Point2f(0, src.rows);
			}
		}
		else
		{
			// 右
			if (corners[i].y < gray.cols >> 1)
			{
				// 上
				affine_result[i] = Point2f(src.cols, 0);
			}
			else
			{
				// 下
				affine_result[i] = Point2f(src.cols, src.rows);
			}
		}

	}


	cout << "角点" << corners << endl;


	//  图像校正
	Mat M = getAffineTransform(affine_target, affine_result);
	Mat dst(src.size(), src.type());
	warpAffine(src, dst, M, src.size(), 1, 0, Scalar::all(255));

	imshow("校正图", dst);


	// 二维码扫描
	ImageScanner scanner;
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

	//图片转换
	Mat imageGray;
	cvtColor(dst, imageGray, CV_RGB2GRAY);
	int w = imageGray.cols;
	int h = imageGray.rows;
	uchar* raw = (uchar*)imageGray.data;

	Image imageZbar(w, h, "Y800", raw, w * h);
	scanner.scan(imageZbar);   
	Image::SymbolIterator symbol = imageZbar.symbol_begin();
	//扫描结果打印
	if (imageZbar.symbol_begin() == imageZbar.symbol_end())
	{
		cout << "查询条码失败，请检查图片！" << endl;
	}
	for (; symbol != imageZbar.symbol_end(); ++symbol)
	{
		cout << "类型：" << endl << symbol->get_type_name() << endl << endl;
		cout << "条码：" << endl << symbol->get_data() << endl << endl;
	}

	imageZbar.set_data(NULL, 0);//清除缓存



	waitKey(0);
	return 0;
}
