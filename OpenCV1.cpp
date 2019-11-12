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
		// ��ȡ��ǰ�е��׵�ַ
		uchar *ptr2i = mat->ptr<uchar>(i);

		for (int j = 0; j < mat->cols; j++)
		{
			int b = ptr2i[0];
			int g = ptr2i[1];
			int r = ptr2i[2];

			// �Ҷ�ͼ rgb����ֵ���ֵ����0.11R+0.59G+0.30B
			int gray = 0.11 * r + 0.59 * g + 0.30 * b;
			ptr2i[0] = gray;
			ptr2i[1] = gray;
			ptr2i[2] = gray;

			// ƽ��ָ��������ɫͨ��
			ptr2i += mat->channels();
		}

	}
}

// ��ƬЧ��
inline void bgr2Negative(Mat* mat)
{
	for (int i = 0; i < mat->rows; i++)
	{
		// ��ȡ��ǰ�е��׵�ַ
		uchar* ptr2i = mat->ptr<uchar>(i);

		for (int j = 0; j < mat->cols; j++)
		{
			uchar b = ptr2i[0];
			uchar g = ptr2i[1];
			uchar r = ptr2i[2];

			// ��ƬЧ�� 255- ��Ӧͨ����ֵ����
			ptr2i[0] = 255-b;
			ptr2i[1] = 255-g;
			ptr2i[2] = 255-r;

			// ƽ��ָ��������ɫͨ��
			ptr2i += mat->channels();
		}

	}
}


// ���Ͷ�
inline void bgr2Saturated(Mat* mat)
{
	for (int i = 0; i < mat->rows; i++)
	{
		// ��ȡ��ǰ�е��׵�ַ
		uchar* ptr2i = mat->ptr<uchar>(i);

		for (int j = 0; j < mat->cols; j++)
		{
			uchar b = ptr2i[0];
			uchar g = ptr2i[1];
			uchar r = ptr2i[2];

			// ���Ͷȸ�ͨ��ֵ*1.2�Ҳ�����255
			ptr2i[0] = saturate_cast<uchar>(1.2 * b);
			ptr2i[1] = saturate_cast<uchar>(1.2 * g);
			ptr2i[2] = saturate_cast<uchar>(1.2 * r);

			// ƽ��ָ��������ɫͨ��
			ptr2i += mat->channels();
		}

	}
}

  ֻ����һ��main������һ��cpp�ļ�����main������Ҫ���˴���main����ע�͵�
int main()
{

	// imread ��ȡһ��ͼƬ������һ��mat����
	Mat src = imread("C:/Users/ubt/Desktop/image1.png");


	imshow("src", src);
	
	imwrite("C:/Users/ubt/Desktop/imag_copy.png",src);

	//Mat dst;
	//cvtColor(src,dst,COLOR_BGR2GRAY);

	//imshow("dst", dst);

	// �������������ɫͨ����channelsֵΪ3��ô��ʾ����ͼ�����ص����ɫͨ��ֵΪ3�ֽڵ�BGR
	printf("width=%d,height=%d,channels=%d", src.cols, src.rows, src.channels());

	bgr2Saturated(&src);

	imshow("Saturated", src);

	waitKey(0);
	return 0;
}*/