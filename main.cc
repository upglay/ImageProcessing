#include <opencv\cv.h>
#include <opencv\highgui.h>

using namespace cv;
using namespace std;

int main()
{


	Mat srcImage = imread("sample2.bmp");
	if (srcImage.empty()) return -1;

	Mat hsv, hsvY, hsvG, hsvB, hsvR, hsvR2;
	cvtColor(srcImage, hsv, CV_BGR2HSV);
	inRange(hsv, Scalar(22, 100, 100), Scalar(38, 255, 255), hsvY); // Yellow
	inRange(hsv, Scalar(100, 100, 100), Scalar(110, 255, 255), hsvB); // Blue
	inRange(hsv, Scalar(50, 90, 70), Scalar(80, 255, 255), hsvG); // Green
	inRange(hsv, Scalar(0, 100, 100), Scalar(20, 255, 255), hsvR); // Lower Red
	inRange(hsv, Scalar(160, 100, 100), Scalar(180, 255, 255), hsvR2); // Upper Red
	addWeighted(hsvR, 1.0, hsvR2, 1.0, 0.0, hsvR);



	vector<int> params;
	params.push_back(IMWRITE_JPEG_QUALITY);
	params.push_back(100);
	imwrite("sample1_outR.jpg", hsvR, params);
	imwrite("sample1_outG.jpg", hsvG, params);
	imwrite("sample1_outB.jpg", hsvB, params);
	imwrite("sample1_outY.jpg", hsvY, params);

	IplImage* img_r_ = cvLoadImage("sample1_outR.jpg");
	IplImage* img_g_ = cvLoadImage("sample1_outG.jpg");
	IplImage* img_b_ = cvLoadImage("sample1_outB.jpg");
	IplImage* img_y_ = cvLoadImage("sample1_outY.jpg");

	IplImage* dst_r_ = cvCreateImage(cvGetSize(img_r_), IPL_DEPTH_8U, 3);
	IplImage* dst_g_ = cvCreateImage(cvGetSize(img_g_), IPL_DEPTH_8U, 3);
	IplImage* dst_b_ = cvCreateImage(cvGetSize(img_b_), IPL_DEPTH_8U, 3);
	IplImage* dst_y_ = cvCreateImage(cvGetSize(img_y_), IPL_DEPTH_8U, 3);

	

	cvDilate(img_r_, dst_r_);
	cvDilate(img_g_, dst_g_);
	cvDilate(img_b_, dst_b_);
	cvDilate(img_y_, dst_y_);

	for (int i = 0; i < 8; i++)
	{
		cvErode(dst_r_, dst_r_);
		cvErode(dst_g_, dst_g_);
		cvErode(dst_b_, dst_b_);
		cvErode(dst_y_, dst_y_);
	}


	//cvErode(img, dst);
	//for (int i = 0; i < 2; i++)
	//	cvErode(dst, dst);
	
	//cvDilate(img, dst);

	//cvShowImage("input_red", img_r_);
	cvShowImage("output_red", dst_r_);

	//cvShowImage("input_green", img_g_);
	cvShowImage("output_green", dst_g_);

	//cvShowImage("input_blue", img_b_);
	cvShowImage("output_blue", dst_b_);

	//cvShowImage("input_yellow", img_y_);
	cvShowImage("output_yellow", dst_y_);

	


	//imshow("dstImage", hsvB);

	waitKey();
	return 0;
}