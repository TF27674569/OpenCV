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

	// 创建一个与原图大小一样的图，并且全部通道的值用0填充
	//Mat des = Mat::zeros(src.size(),src.type());
	//// 列数 需要左移一个所有通道的值（从0开始第一行第一个娶不到上一行和左边一个的值，所以从第二行第二个，到倒数第二行的倒数第二个）
	//int cols = (src.cols-1)*src.channels();
	//int rows = src.rows-1;
	//int offsetx = src.channels();

	//for (int i = 1; i < rows; i++)
	//{
	//	// 上一行
	//	uchar* preLine = src.ptr<uchar>(i - 1);
	//	// 当前行
	//	uchar* curLine = src.ptr<uchar>(i);
	//	// 下一行
	//	uchar* nextLine = src.ptr<uchar>(i + 1);

	//	//需要填充的图片
	//	uchar* desLine = des.ptr<uchar>(i);

	//	// 这里遍历的是每个通道（像素点可能含有rgb三个值不能单独的对整个像素点赋值，只能对其颜色通道的值进行掩模）
	//	for (int j = offsetx; j < cols; j++)
	//	{
	//		// 开始掩模
	//		desLine[j] = saturate_cast<uchar>( 5 * curLine[j] - (preLine[j] + curLine[j - offsetx] + curLine[j + offsetx] + nextLine[j]));
	//	}
	//}
	
	Mat dest;

	// InputArray src 输入
	// OutputArray dst 输出
	// int ddepth 深度
	// InputArray kernel 掩模的核，也就是我们的核心矩阵
	// Point anchor = Point(-1, -1) 默认将点存在中心
	// double delta = 0
	// int borderType = BORDER_DEFAULT
	//Mat kernel = (Mat_<char>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	//filter2D(src,dest,src.depth(),kernel);

	//cout << src.depth() << endl;
	imshow("src",src);
	//InputArray src 输入的Mat
	//OutputArray dst 输出的Mat
	//Size ksize 做模糊操作的核矩阵
	//Point anchor = Point(-1, -1) 描点位置（这里表示为核的中心）
	// blur(src,dest,Size(21,21));

	//InputArray src    输入
	//OutputArray dst   输出
	//int ksize         因为要算取中间值，所以必须传奇数
	//medianBlur(src,dest,5);

	//InputArray src       输入
	//OutputArray dst      输出
	//int d                表示在过滤过程中每个像素邻域的直径范围。如果这个值是非正数，则函数会从第五个参数sigmaSpace计算该值。
	//double sigmaColor    颜色空间过滤器的sigma值，这个参数的值月大，表明该像素邻域内有越宽广的颜色会被混合到一起，产生较大的半相等颜色区域
	//double sigmaSpace    坐标空间中滤波器的sigma值，如果该值较大，则意味着越远的像素将相互影响，从而使更大的区域中足够相似的颜色获取相同的颜色。当d>0时，d指定了邻域大小且与sigmaSpace无关，否则d正比于sigmaSpace.
	//bilateralFilter(src,dest, 15, 100, 5);//后面三个值是，经验值，一般取这三个就行


	//int shape   形状(一般都是矩形)
	//Size ksize  核矩阵 
	Mat kernel = getStructuringElement(MORPH_RECT,Size(30,30));// 这里是一个15x15的正方形
	//InputArray src     输入
	//OutputArray dst    输出
	//InputArray kernel  核
	erode(src,dest, kernel);// 取最小值黑色区域放大，白色区域缩小


	dilate(src,dest, kernel);// 取最大值白色区域放大，黑色区域缩小

	imshow("des", dest);
	waitKey(0);
	return 0;
}
*/