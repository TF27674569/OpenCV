#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "zbar.h"


#pragma comment(lib,"opencv_world344d.lib")
#pragma comment(lib,"libzbar64-0.lib")

using namespace zbar;


using namespace cv;
using namespace std;

/**
 * 仿射变换，将一张图片的（A,B,C,D）四个点变换到另外一张图片的（A',B',C',D'）的位置
 */
Mat warpTransfrom(const Mat &gray, const RotatedRect &rect)
{
	int width = rect.size.width;
	int height = rect.size.height;
	// 仿射变换后的图片
	Mat result(Size(width, height), gray.type());

	// 找出这个矩形的四个顶点
	Point2f pts[4];
	rect.points(pts);

	// 需要变换的点集合（findHomography）必须四个点
	vector<Point> src_point;
	vector<Point> res_point;

	for (int i = 0; i < 4; i++)
	{
		src_point.push_back(pts[i]);
	}

	// 四个点的对应点 闭环
	res_point.push_back(Point(width, height));
	res_point.push_back(Point(0, height));
	res_point.push_back(Point(0, 0));
	res_point.push_back(Point(width, 0));

	// InputArray srcPoints 输入的点
	// InputArray dstPoints 输出的点
	// return 经过算法计算的到，变换的矩阵 将一张图片的（A,B,C,D）四个点变换到另外一张图片的（A',B',C',D'）的位置
	Mat M = findHomography(src_point, res_point);

	// InputArray src  输入图像
	// OutputArray dst 输出图像
	// InputArray M    仿射变换矩阵
	// Size dsize      输出图像的大小
	warpPerspective(gray, result, M, result.size());


	return result;
}

bool isXCorner(const Mat& qrROI) {
	// 四个值 
	int cb = 0, lw = 0, rw = 0, lb = 0, rb = 0;

	int width = qrROI.cols;
	int height = qrROI.rows;
	int cx = width / 2;
	int cy = height / 2;
	uchar pixels = qrROI.at<uchar>(cy, cx);
	if (pixels == 255) {
		return false;
	}

	// 求中心黑色
	int start = 0, end = 0, offset = 0;
	bool findleft = false, findright = false;
	while (true) {
		offset++;

		if ((cx - offset) <= 0 || (cx + offset) >= width - 1) {
			break;
		}

		// 左边扫
		pixels = qrROI.at<uchar>(cy, cx - offset);
		if (!findleft && pixels == 255) {
			start = cx - offset;
			findleft = true;
		}

		// 右边扫
		pixels = qrROI.at<uchar>(cy, cx + offset);
		if (!findright && pixels == 255) {
			end = cx + offset;
			findright = true;
		}

		if (findleft && findright) {
			break;
		}
	}
	if (start == 0 || end == 0) {
		return false;
	}
	cb = end - start;
	// 相间的白色
	for (int col = end; col < width - 1; col++)
	{
		pixels = qrROI.at<uchar>(cy, col);
		if (pixels == 0) {
			break;
		}
		rw++;
	}
	for (int col = start; col > 0; col--)
	{
		pixels = qrROI.at<uchar>(cy, col);
		if (pixels == 0) {
			break;
		}
		lw++;
	}
	if (rw == 0 || lw == 0) {
		return false;
	}

	// 两边的黑色
	for (int col = end + rw; col < width - 1; col++)
	{
		pixels = qrROI.at<uchar>(cy, col);
		if (pixels == 255) {
			break;
		}
		rb++;
	}
	for (int col = start - lw; col > 0; col--)
	{
		pixels = qrROI.at<uchar>(cy, col);
		if (pixels == 255) {
			break;
		}
		lb++;
	}
	if (rb == 0 || lb == 0) {
		return false;
	}

	float sum = cb + lb + rb + lw + rw;
	// 求比例 3:1:1:1:1
	cb = (cb / sum) * 7.0 + 0.5;
	lb = (lb / sum) * 7.0 + 0.5;
	rb = (rb / sum) * 7.0 + 0.5;
	lw = (lw / sum) * 7.0 + 0.5;
	rw = (rw / sum) * 7.0 + 0.5;

	if ((cb == 3 || cb == 4) && (lw == rw) && (lb == rb) && (lw == rb) && (lw == 1)) {
		// 3:1:1:1:1 or 4:1:1:1:1
		return true;
	}

	return false;
}


/**
 * 判断区域内的像素比
 */
bool isYCorner(const Mat& qrROI) {
	// 统计白色像素点和黑色像素点
	int bp = 0, wp = 0;
	int width = qrROI.cols;
	int height = qrROI.rows;
	int cx = width / 2;

	// 中心点是黑的
	int pv = 0;

	for (int row = 0; row < height; row++)
	{
		pv = qrROI.at<uchar>(row, cx);
		if (pv == 0) {
			bp++;
		}
		else if (pv == 255) {
			wp++;
		}
	}

	if (bp == 0 || wp == 0) {
		return false;
	}

	//最正规黑白比 33：16，这里需要放宽判断的要求 wp 10 bp 43
	if (wp * 2 > bp || bp > 5 * wp) {
		return false;
	}

	return true;
}

/*
int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/opencv/qr2.jpg");

	if (!src.data)
	{
		printf("src imread error");
		return -1;
	}
	//blur(src, src,Size(3,3));
	imshow("src", src);

	Mat gray;
	cvtColor(src,gray,COLOR_BGR2GRAY);

	// 二值化
	threshold(gray, gray, 0, 255, THRESH_OTSU | THRESH_BINARY);

	// 降噪 ？ 每有将下面的小黑点处理掉
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	morphologyEx(gray, gray, CV_MOP_CLOSE, kernel);

	imshow("gray", gray);

	// 提取轮廓 CV_RETR_LIST 所有轮廓
	vector<vector<Point>> contours;
	findContours(gray, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);

	imshow("contours", gray);

	float angle = 0.0f;

	// 遍历所有轮廓进行过滤
	for (int i = 0; i < contours.size(); i++)
	{
		vector<Point> contour = contours[i];
		// 返回面积 contourArea获取 contour 的面积
		double area = contourArea(contour);

		//drawContours(src, contours, i, Scalar(0, 0, 255), 4);
		// 49 7*7  最少每个点占一个像素 小于49 不予处理
		if (area <49) {
			continue;
		}

		// 根据这些点，生成最小的外接矩形
		RotatedRect minRect = minAreaRect(contour);
		float w = minRect.size.width;
		float h = minRect.size.height;

		// 判断宽高比（是否是正方形 1：1 ,有些图片是斜着拍的可能是0.8：1,这里放宽的条件自己制定）
		float rotio = min(w,h) / max(w,h);// 小边：大边

		// 宽高比大于0.7
		// 宽与高不能大于 这个图像的一半的，否则三个固定点在这张图里面是放不下的
		if (rotio > 0.7 && w < gray.cols / 2 && h < gray.rows / 2)
		{
			// 做图像的仿射变换 让非垂直拍摄的图片，转为垂直拍摄
			Mat qr_ROI = warpTransfrom(gray, minRect);
			// x y 判断
			if (isYCorner(qr_ROI)&& isXCorner(qr_ROI)) {
				//drawContours(src, contours, i, Scalar(0, 0, 255), 4);
				// minRect 包含了旋转角度和，控制点中心的信息，够三个则认为是一个二维码
				angle = minRect.angle;
			}
		}
	}

	Point2f center((float)(src.cols / 2), (float)(src.rows / 2));
	Mat affine_matrix = getRotationMatrix2D(center, angle, 1.0);//求得旋转矩阵

	Mat dst;
	warpAffine(src, dst, affine_matrix, dst.size());


	imshow("resu", dst);


	//定义扫描器
	ImageScanner scanner;
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

	//图片转换
	Mat imageGray;
	cvtColor(dst, imageGray, CV_RGB2GRAY);
	int width = imageGray.cols;
	int height = imageGray.rows;
	uchar* raw = (uchar*)imageGray.data;

	Image imageZbar(width, height, "Y800", raw, width * height);
	scanner.scan(imageZbar); //扫描条码    
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

	//显示二维码
	imshow("Source Image", dst);
	waitKey();


	waitKey(0);
	return 0;
}
*/