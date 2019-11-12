#include<stdio.h>
#include<stdlib.h>
#include<opencv2/opencv.hpp>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;

/*
inline void bgr2Gray(Mat *mat) 
{
	for (int i = 0; i < mat->rows;i++)
	{
		// 读取当前行的首地址
		uchar *ptr2i = mat->ptr<uchar>(i);

		for (int j = 0; j < mat->cols; j++)
		{
			int b = ptr2i[0];
			int g = ptr2i[1];
			int r = ptr2i[2];

			// 灰度图 rgb三个值相等值等于0.11R+0.59G+0.30B
			int gray = 0.11 * r + 0.59 * g + 0.30 * b;
			ptr2i[0] = gray;
			ptr2i[1] = gray;
			ptr2i[2] = gray;

			// 平移指针三个颜色通道
			ptr2i += mat->channels();
		}

	}
}

// 底片效果
inline void bgr2Negative(Mat* mat)
{
	for (int i = 0; i < mat->rows; i++)
	{
		// 读取当前行的首地址
		uchar* ptr2i = mat->ptr<uchar>(i);

		for (int j = 0; j < mat->cols; j++)
		{
			uchar b = ptr2i[0];
			uchar g = ptr2i[1];
			uchar r = ptr2i[2];

			// 底片效果 255- 对应通道的值即可
			ptr2i[0] = 255-b;
			ptr2i[1] = 255-g;
			ptr2i[2] = 255-r;

			// 平移指针三个颜色通道
			ptr2i += mat->channels();
		}

	}
}


// 饱和度
inline void bgr2Saturated(Mat* mat)
{
	for (int i = 0; i < mat->rows; i++)
	{
		// 读取当前行的首地址
		uchar* ptr2i = mat->ptr<uchar>(i);

		for (int j = 0; j < mat->cols; j++)
		{
			uchar b = ptr2i[0];
			uchar g = ptr2i[1];
			uchar r = ptr2i[2];

			// 饱和度各通道值*1.2且不超过255
			ptr2i[0] = saturate_cast<uchar>(1.2 * b);
			ptr2i[1] = saturate_cast<uchar>(1.2 * g);
			ptr2i[2] = saturate_cast<uchar>(1.2 * r);

			// 平移指针三个颜色通道
			ptr2i += mat->channels();
		}

	}
}

  只能有一个main函数另一个cpp文件定义main函数需要将此处的main函数注释掉
int main()
{

	// imread 读取一张图片，返回一个mat对象
	Mat src = imread("C:/Users/ubt/Desktop/image1.png");


	imshow("src", src);
	
	imwrite("C:/Users/ubt/Desktop/imag_copy.png",src);

	//Mat dst;
	//cvtColor(src,dst,COLOR_BGR2GRAY);

	//imshow("dst", dst);

	// 这里读出来的颜色通道数channels值为3那么表示这张图的像素点的颜色通道值为3字节的BGR
	printf("width=%d,height=%d,channels=%d", src.cols, src.rows, src.channels());

	bgr2Saturated(&src);

	imshow("Saturated", src);

	waitKey(0);
	return 0;
}*/