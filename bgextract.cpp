#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <Algorithm>
#include <opencv2\opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "bgextract.h"
#include <ctime>
#include <string>
#include <Windows.h>
using namespace cv;
using namespace std;
string bgextractfilename()
{
	string ar;
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	char buffer[100];
	sprintf(buffer, "bg_%d%d%d%d%d%d", now->tm_mday, now->tm_mon, (1900 + now->tm_year), now->tm_hour, now->tm_min, now->tm_sec);
	return buffer;

}
bool dirExists(const std::string& dirName_in)
{
	DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}
int main1(char* argc)
{


     int i = 0, j = 0, k = 0;
	double r,g, b;
	Mat inp;

	vector<Mat> frame;
	string arg = string(argc);
	VideoCapture cap(arg);
	if (!cap.isOpened())
	{
		cap.release();
		Mat error = imread("Error.jpg");
		imshow("error", error);
		waitKey(2000);
		destroyWindow("error");
		return -1;
	}

		int frcount = cap.get(CV_CAP_PROP_FRAME_COUNT);
		int fwidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
		int fheight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
		namedWindow("Video", CV_WINDOW_KEEPRATIO);
		for (int h = 0; h < frcount; h++)
		{
			frame.push_back(Mat());
			cap >> inp;
			inp.copyTo(frame.back());
			imshow("Video", frame[h]);
			waitKey(30);

		}
		destroyWindow("Video");
		Mat finale(inp.size(), inp.type());
		finale = Scalar::all(0);
		for (i = 0; i < fheight; i++)
		{
			namedWindow("finale", CV_WINDOW_KEEPRATIO);
			imshow("finale", finale);
			waitKey(1);
			for (j = 0; j < fwidth; j++)
			{
				r = 0; g = 0; b = 0;
				for (k = 0; k < frcount; k++)
				{
					r += frame[k].at<Vec3b>(i, j)[0];
					g += frame[k].at<Vec3b>(i, j)[1];
					b += frame[k].at<Vec3b>(i, j)[2];
				}

				r = r / frcount;
				g = g / frcount;
				b = b / frcount;
				finale.at<Vec3b>(i, j)[0] = r;

				finale.at<Vec3b>(i, j)[1] = g;

				finale.at<Vec3b>(i, j)[2] = b;
			}

		}

		imshow("finale", finale);
		string ar = "C:/Users/HITESH/Pictures/motioCam/" + bgextractfilename() + ".jpeg";
		imwrite(ar, finale);
		waitKey(0);
		destroyWindow("finale");
		return 0;
	
	

	
}