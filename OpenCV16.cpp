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

	// InputArray img ԭͼ�� ֻ֧��CV_8UC1��CV_8UC4�������͡�
	// CV_OUT std::vector<float>& descriptors  ���ص�HOG����������descriptors.size��HOG������ά��
	// Size winStride = Size() �����ƶ�������
	// Size padding = Size()  ������������
	// const std::vector<Point>& locations = std::vector<Point>()��������������ֱ��ȡ(0,0),������Ϊ��������������귶Χ�ڵĵ����ꡣ
	
	// ����HOG�������� 
	hogDescriptor.compute(dst_gary, descriptors, Size(), Size(), locations);


	// ���˼��
	HOGDescriptor defaultHog;
	// ��ȡopcv�ṩ��Ĭ�ϵ�people�ķ�����

	defaultHog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
	vector<Rect> found;
	//���м��
	defaultHog.detectMultiScale(dst_gary, found ,0, Size(8, 8));
	//�������Σ��������
	for (int i = 0; i < found.size(); i++)
	{
		Rect r = found[i];
		rectangle(src, r.tl(), r.br(), Scalar(0, 0, 255), 3);
	}

	imshow("�������", src);

	waitKey(0);
	return 0;
}
*/