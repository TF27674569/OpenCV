#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;
/*
int main()
{

	Mat src = imread("C:/Users/ubt/Desktop/opencv/people.jpeg");
	if (!src.data)
	{
		printf("src imread error");
		return -1;
	}

	Mat dst, dst_gary;
	resize(src, dst, Size(64, 128));
	cvtColor(src, dst_gary, COLOR_BGR2GRAY);

	HOGDescriptor hogDescriptor;
	vector<float> descriptors;
	vector<Point> locations;

	// InputArray img 原图像 只支持CV_8UC1和CV_8UC4数据类型。
	// CV_OUT std::vector<float>& descriptors  返回的HOG特征向量，descriptors.size是HOG特征的维数
	// Size winStride = Size() 窗口移动步长。
	// Size padding = Size()  扩充像素数。
	// const std::vector<Point>& locations = std::vector<Point>()对于正样本可以直接取(0,0),负样本为随机产生合理坐标范围内的点坐标。
	
	// 计算HOG特征向量 
	hogDescriptor.compute(dst_gary, descriptors, Size(), Size(), locations);


	// 行人检测
	HOGDescriptor defaultHog;
	// 获取opcv提供的默认的people的分类器

	defaultHog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
	vector<Rect> found;
	//进行检测
	defaultHog.detectMultiScale(dst_gary, found ,0, Size(8, 8));
	//画长方形，框出行人
	for (int i = 0; i < found.size(); i++)
	{
		Rect r = found[i];
		rectangle(src, r.tl(), r.br(), Scalar(0, 0, 255), 3);
	}

	imshow("检测行人", src);

	waitKey(0);
	return 0;
}
*/