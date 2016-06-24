#include "stdafx.h"
#include <stdio.h>//
#include <iostream>
#include <opencv2\opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "bgextract.h"
#include "static_pic.h"
#include "videosurv.h"
#include "negfil.h"
#include "sepfil.h"
#include "canfil.h"
#include "grafil.h"
#include "help.h"
#include <windows.h>
using namespace cv;
using namespace std;
Mat src;
int curchoice = 0, cur = 0;  int textflag = 1;
char i[1000];
string ar;

void mouse_caller(int event, int x, int y, int flags, void* userdata)
{

	if (event == EVENT_MOUSEMOVE){

		/*{
		cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
		}*/

		if (x > 161 && x<344 && y>152 && y < 331)
		{
			if ((curchoice != 1) && cur == 0)

			{
				src = imread("C:/Users/HITESH/Documents/Visual Studio 2013/Projects/Final_Pro/Pics/Selected_BGExtrac.jpg");
				imshow("motioCam", src);
				curchoice = 1;
				textflag = 1;

			}

		}
		else if (x > 161 && x<344 && y>384 && y < 560)
		{
			if ((curchoice != 2) && cur == 0)

			{
				src = imread("C:/Users/HITESH/Documents/Visual Studio 2013/Projects/Final_Pro/Pics/Selected_SC.jpg");
				imshow("motioCam", src);
				curchoice = 2;
				textflag = 0;
			}

		}
		else if (x > 466 && x<649 && y>383 && y < 561)
		{
			if ((curchoice != 3) && cur == 0)

			{
				src = imread("C:/Users/HITESH/Documents/Visual Studio 2013/Projects/Final_Pro/Pics/Selected_filter.jpg");
				imshow("motioCam", src);
				curchoice = 3;
				textflag = 0;
			}

		}
		else if (x > 466 && x<649 && y>151 && y < 330)
		{
			if ((curchoice != 4) && cur == 0)

			{
				src = imread("C:/Users/HITESH/Documents/Visual Studio 2013/Projects/Final_Pro/Pics/Selected_vs.jpg");
				imshow("motioCam", src);
				curchoice = 4;
				textflag = 0;
			}

		}
		else if (cur == 0)
		{
		label2:
			cur = 0;

			src = imread("C:/Users/HITESH/Documents/Visual Studio 2013/Projects/Final_Pro/Pics/Home.jpg");
			imshow("motioCam", src);
			curchoice = 0; 
		 	setMouseCallback("motioCam", mouse_caller, NULL);
			
		}


	}

	if ((event == EVENT_LBUTTONDOWN))
	{
		if (x >0 && x<107 && y>0 && y < 39)
		{
			helper();
		}

		if (curchoice == 1)
		{
		//label1:
			
			src = imread("C:/Users/HITESH/Documents/Visual Studio 2013/Projects/Final_Pro/Pics/Video_Dir.jpg");
			imshow("motioCam", src);
		
			int c = 0; int end = 0; i[0] = '\0'; int re = 0;
			
			if (event == EVENT_LBUTTONDOWN)
			{
				if (x > 322 && x<471 && y>265 && y < 471)
				{
					if (cur == 1)
					{
						textflag = 0;
						cur = 0;
						goto label2;
					}
				}
			}
		
				cur = 1;
				
				while (textflag == 1)
				{
				   label1:
					re = 0;
					textflag = 1;
						
						imshow("motioCam", src);
						c = waitKey(5);

						if ((textflag == 1) && (c != -1))
						{
						
							
							src = imread("C:/Users/HITESH/Documents/Visual Studio 2013/Projects/Final_Pro/Pics/Video_Dir.jpg");
							src = src.clone();
							if (c == 8)
							{
								if (end)
								{

									end--;
									i[end] = '\0';

								}
							}
							else if (c == 13)
							{
								textflag = 0;
								re = 1;

							}
							else
							{
								i[end] = c;
								end++;
								i[end] = '\0';
							}
							
							ar = string(i);
							putText(src, ar, Point(123, 209), 3, 1.0, Scalar(130, 162, 234), 1.5);

						}

					}
					if (re == 1)
					{
						int ret = main1(i);
						if (ret == -1)
						goto label1;
						if (ret == 0)
							goto label2;
					}
				
		}
		else if (curchoice == 2)
		{
			cur = 2;
			destroyWindow("motioCam");
			int ret = static_pic();
			if (ret == -1)
				goto label2;
		}
		else if (curchoice == 3)
		{
		label3:
		
			src = imread("C:/Users/HITESH/Documents/Visual Studio 2013/Projects/Final_Pro/Pics/filter.jpg");
			imshow("motioCam", src);
			setMouseCallback("motioCam", mouse_caller, NULL);
			if ((x > 70 && x<293 && y>131 && y < 338) && (cur == 3))
			{
				destroyWindow("motioCam");
				int ret = gfi();
				if (ret == -1)
				{
					cur = 0;
					goto label3;

				}
			}
			else if ((x > 500 && x<723 && y>131 && y < 338) && (cur == 3))
			{
				destroyWindow("motioCam");
				int ret = nfi();
				if (ret == -1)
				{
					cur = 0;
					goto label3;
				}
			}
			else if ((x > 161 && x<344 && y>404 && y < 613) && (cur == 3))
			{
				destroyWindow("motioCam");
				int ret = cfi();
				if (ret == -1)
				{
					cur = 0;
					goto label3;
				}
			}
			else if ((x > 500 && x<723 && y>404 && y < 613) && (cur == 3))
			{
				destroyWindow("motioCam");
				int ret = sfi();
				if (ret == -1)
				{
					cur = 0;
					goto label3;
				}
			}

			else if (x > 0 && x<36 && y>281 && y < 461)
			{
				goto label2;
			}

			cur = 3;

		}
		else if (curchoice == 4)
		{
			cur = 4;
			destroyWindow("motioCam");

			int ret = vs();
			if (ret == -1)
				goto label2;
		}
	}

}




int main(int argc, char* argv[])
{
	FreeConsole();
	src = imread("C:/Users/HITESH/Documents/Visual Studio 2013/Projects/Final_Pro/Pics/start.jpg");
	imshow("motioCam", src);
	cvWaitKey(3000);
	curchoice = 0; cur = 0;
	src = imread("C:/Users/HITESH/Documents/Visual Studio 2013/Projects/Final_Pro/Pics/Home.jpg");
	imshow("motioCam", src);
	setMouseCallback("motioCam", mouse_caller, NULL);
	waitKey(0);
	return 0;
}