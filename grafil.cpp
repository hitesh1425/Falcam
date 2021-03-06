#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "grafil.h"
#include <ctime>
using namespace cv;
using namespace std;
string grayfilename()
{
	string ar;
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	char buffer[100];
	sprintf(buffer, "gray_%d%d%d%d%d%d", now->tm_mday, now->tm_mon, (1900 + now->tm_year), now->tm_hour, now->tm_min, now->tm_sec);
	return buffer;

}

int gfi()
{  
	namedWindow("Cam", CV_WINDOW_KEEPRATIO);
	Mat frame;
	int c = waitKey(5), started = 0;
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		return -1;
	}
	while (1)
	{
		c = waitKey(5);
		cap >> frame;
		cvtColor(frame, frame, CV_BGR2GRAY);
		if (c == 's')
		{
			namedWindow("Captured", CV_WINDOW_AUTOSIZE);
			imshow("Captured", frame);
			string loc ="C:/Users/HITESH/Pictures/motioCam/"+grayfilename()+".jpg";
			imwrite(loc, frame);
			waitKey(500);
			destroyWindow("Captured");
		
		}
		if (c == 'q')
		{
			destroyWindow("Cam");
			destroyWindow("Captured");
			return -1;
		}
		imshow("Cam", frame);
	}
	//namedWindow("Captured", CV_WINDOW_KEEPRATIO);
	//imshow("Captured", frame);
	//destroyWindow("Cam");
	//cap.release();
	//waitKey(3000);
	//destroyWindow("Captured");
	return 0;
}