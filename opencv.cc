#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace cv;

int main()
{
	IplImage *frame;
	IplImage *red;
	IplImage *blue;
	IplImage *green;
	IplImage *yellow;

	int width, height;
	int i, j, index;
	unsigned char R, G, B;


	Mat img_color = imread("sample2.bmp");		//color load
	Mat img_gray = imread("", 0);	//gray load


	imwrite("fname.bmp", img_color);


}