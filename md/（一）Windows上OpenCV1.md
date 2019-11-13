### Windows上OpenCV安装与环境

1.下载opencv.exe并解压</br>
2.配置环境变量 D:\opencv\opencv\build\x64\vc14\bin D:\opencv是解压目录</br>
3.VS上新建项目</br>
4.配置include目录：调试->xxx属性->配置属性->vc++目录->包含目录（这里选择解压后的include目录）</br>
5.配置库目录：调试->xxx属性->配置属性->vc++目录->库目录（lib目录）D:\opencv\opencv\build\x64\vc14\lib</br>
6.Debug旁边选择x64没有就配置一个并选择x64</br>
7.新建cpp文件：#pragma comment(lib,"opencv_world344d.lib")链接库显示调用</br>

可以开始编程，如果运行时报错说缺少那个dll库直接将dll库丢到system32文件夹中即可<font color=#ff0000>（代码在OpenCV1.cpp）</font>


</br></br></br></br>




开始一段程序,此段程序显示一张图片
```c++
#include<stdio.h>
#include<stdlib.h>
#include<opencv2/opencv.hpp>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;


int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/image1.png");

	imshow("src",src);
	waitKey(0);
	return 0;
}
```
imread： 读取一张图片文件并返回一个Mat对象，Mat对象是一个BGR三颜色通道的矩阵</br>
imshow：在窗口显示一个Mat图像举证</br>

显示灰度图</br>
1.使用opencv函数cvtColor
```c++
int main()
{
	// imread 读取一张图片，返回一个mat对象
	Mat src = imread("C:/Users/ubt/Desktop/image1.png");
	
	//Mat dst;
	cvtColor(src,dst,COLOR_BGR2GRAY);
	imshow("dst", dst);
	
	waitKey(0);
	return 0;
}
```
cvtColor：将源矩阵转换成目标矩阵按照type（COLOR_BGR2GRAY）类型</br></br></br>
2.使用像素操作手写灰度</br>
```c++
inline void bgr2Gray(Mat *mat) 
{
	for (int i = 0; i < mat->rows;i++)
	{
		// 读取当前行的首地址
		uchar *ptr2i = mat->ptr<uchar>(i);

		for (int j = 0; j < mat->cols; j++)
		{
			uchar b = ptr2i[0];
			uchar g = ptr2i[1];
			uchar r = ptr2i[2];

			// 灰度图 rgb三个值相等值等于0.11R+0.59G+0.30B
			uchar gray = 0.11 * r + 0.59 * g + 0.30 * b;
			ptr2i[0] = gray;
			ptr2i[1] = gray;
			ptr2i[2] = gray;

			// 平移指针三个颜色通道
			ptr2i += mat->channels();
		}

	}
}

int main()
{

	// imread 读取一张图片，返回一个mat对象
	Mat src = imread("C:/Users/ubt/Desktop/image1.png");
	
	// 这里读出来的颜色通道数channels值为3那么表示这张图的像素点的颜色通道值为3字节的BGR
	printf("列=%d,行=%d,channels=%d", src.cols, src.rows, src.channels());
	bgr2Gray(&src);
	imshow("src", src);
	waitKey(0);
	return 0;
}

```
主函数中打印了行数，列数，还有颜色通道数，这里的颜色通道数为3，表示了三颜色BGR通道，操作像素时，每行每行的读然后，像素每三个三个的处理</br>
</br>

底片效果
```c++
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
```
</br></br></br>

增加饱和度
```c++
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

```




