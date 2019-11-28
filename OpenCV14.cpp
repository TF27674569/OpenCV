#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "OpenCV14.h"

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;

/**
 * ��ֲ��ĺͣ�����ƽ���ͣ�
 * sum������ͼ
 * x0,y0,  x1, y1�����ϽǺͣ����½ǵ�����������
 * channel��ͨ����
 */
int getBlockSum(const Mat &sum,int x0, int y0, int x1, int y1,int channel) {
	// ����+����-����-����
	int lt = sum.at<Vec3i>(y0, x0)[channel];
	int rt = sum.at<Vec3i>(y1, x0)[channel];
	int lb = sum.at<Vec3i>(y0, x1)[channel];
	int rb = sum.at<Vec3i>(y1, x1)[channel];
	return lt+ rb- rt- lb;
}


/**
 * size��ģ���뾶
 * singam����kֵʹ�õ�һ��ֵ
 */
void integralBlur(const Mat &src, Mat &dst, int size, int sigma)
{
	// �ڼ���ӻ���ͼ֮ǰ�Ƚ���srcͼ���Ե���һ��,ʹ��BORDER_DEFAULT��ȡ��Եֵ
	Mat mat;
	int radius = size / 2;
	copyMakeBorder(src, mat, radius, radius, radius, radius, BORDER_DEFAULT);

	//1. �������ͼ�õ�����ͼ�����غ������ͼ������ƽ����
	Mat sum_mat;
	Mat sqsum_mat;
	// ��ͨ����ɫ�Ļ���ͼֵ���ܳ���CV_8UC3 ʹ��CV_32S
	integral(mat, sum_mat, sqsum_mat,CV_32S, CV_32S);

	//2. ͨ������ͼ������ֲ����صĺ���ֲ����ص�ƽ����
	// ���ͼ��
	dst.create(src.size(), src.type());

	// ͨ����
	int channels = src.channels();

	// ������ظ���
	int pix_area = size * size;

	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			int x0 = col;
			int y0 = row;
			int x1=  col+size;
			int y1 = row + size;

			// �������ͨ����ֵ
			for (int ch = 0; ch < channels; ch++)
			{

				//3. ͨ����ʽ���㷽��
				// ��Ҫ ƽ���� �� �͵�ƽ�� 
				// �����
				int sum = getBlockSum(sum_mat, x0, y0, x1, y1, ch);
				float sqsum = getBlockSum(sqsum_mat, x0, y0, x1, y1, ch);
				// ���㷽�� 1/n *( \sum_{i=1 }^{n}x(i)^2-1/n *( \sum_{i=1 }^{n}x(i))^2)
				// ��sqsum - 1/���ظ���*��sum��ƽ������/���ظ���
				float diff_sum = (sqsum - sum * sum / pix_area) / pix_area;

				//4. ͨ���������k
				float k = diff_sum / (diff_sum + sigma);

				//5. ͨ���ֲ��ĺ�����ֲ�ƽ��ֵ = �ֲ����غ�/���ظ���
				float average_sum = sum / pix_area;

				//6. ͨ��k�������ǰ���صı�Ե�������ֵ =  (1-k)ƽ��ֵ+k*ԭ����ֵ
				int pixels = src.at<Vec3b>(row, col)[ch];
				pixels = (1 - k)* average_sum + k * pixels;
				dst.at<Vec3b>(row, col)[ch] = pixels;
				
			}
		}
	}
}

/**
 *���Ƥ������Ƥ������Ϊ��255  ��������Ϊ��0
 */
void skinDetect(const Mat &src,Mat &dst) 
{
	dst.create(src.size(),CV_8UC1);
	Mat skin_ycbcr;
	cvtColor(src, skin_ycbcr, COLOR_BGR2YCrCb);

	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			Vec3b pixels = src.at<Vec3b>(row, col);
			uchar y = pixels[0];
			uchar cr = pixels[1];
			uchar cb = pixels[2];
			if (y > 80 && 85 < cb < 135 && 135 < cb < 180 )
			{
				dst.at<uchar>(row, col) = 255;
			}else {
				dst.at<uchar>(row, col) = 0;
			}
		}
	}
}
/**
 *ͨ��Ƥ������ϲ�
 *�����Ƥ����ʹ��blur�˲����ͼƬ������ʹ��ԭͼ
 *src��ԭͼ
 *blur�����ٱ�Ե�˲����ͼ
 *skin����Ƥ�����������
 *skinMerge�����صĽ��
 */
void skinMerge(const Mat &src, const Mat& blur, const Mat& skin, Mat& skinMerge)
{
	skinMerge.create(src.size(),src.type());
	
	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			uchar skin_value= skin.at<uchar>(row, col);
			if (skin_value==255)
			{
				skinMerge.at<Vec3b>(row, col) = blur.at<Vec3b>(row, col);
			}
			else 
			{
				skinMerge.at<Vec3b>(row, col) = src.at<Vec3b>(row, col);
			}
		}
	}

}


int main()
{
	Mat src = imread("C:/Users/ubt/Desktop/demo1.png");

	if (!src.data)
	{
		printf("src imread error");
		return -1;
	}

	imshow("ԭͼ", src);

	// ���ٱ�Ե�����˲�
	Mat dst;
	int size = 15;
	integralBlur(src, dst, size, size* size);
	imshow("���ٱ�Ե�˲�", dst);

	// ���Ƥ��
	Mat skin;
	skinDetect(src, skin);
	imshow("���Ƥ��", skin);

	// �ϲ�
	Mat skin_merge;
	skinMerge(src,  dst, skin, skin_merge);
	imshow("�ϲ�", skin_merge);

	// ��������
	add(skin_merge, Scalar(10, 10, 10), skin_merge);
	imshow("��������", skin_merge);

	waitKey(0);
	return 0;
}