#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <iostream>

#pragma comment(lib,"opencv_world344d.lib")

using namespace cv;
using namespace std;


int main()
{
	//Mat src = imread("C:/Users/ubt/Desktop/2_04.png");
	Mat src = imread("C:/Users/ubt/Desktop/gl.png");

	if (!src.data)
	{
		cout << "imread error" << endl;
		return -1;
	}

	imshow("src",src);
	
	//Mat gray;
	//cvtColor(src,gray,COLOR_BGR2GRAY);

	//Mat des;
	//equalizeHist(gray, gray);


	vector<Mat> channls;
	split(src, channls);

	equalizeHist(channls[0], channls[0]);
	equalizeHist(channls[1], channls[1]);
	equalizeHist(channls[2], channls[2]);


	Mat des;
	merge(channls, des);

	imshow("des", des);

	waitKey(0);
	return 0;
}
