#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
using namespace cv;
using namespace std;

int helper()
{
	Mat help = imread("help.jpg");
	imshow("Help", help);
	waitKey(0);
	return 0;
}