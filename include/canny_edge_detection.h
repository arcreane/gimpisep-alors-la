#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
using namespace std;
using namespace cv;

void canny_edge_detection(string filename, double threshold1, double threshold2, double kernel)
{
	Mat input_img, img_gry, img_cny;

	namedWindow("Input Image", WINDOW_AUTOSIZE);
	namedWindow("Canny Image", WINDOW_AUTOSIZE);

	input_img = cv::imread(filename);

	img_cny.create(input_img.size(), input_img.type()); //destination img should be of same size & type as source img
	

	cvtColor(input_img, img_gry, cv::COLOR_BGR2GRAY); //used to convert to gray image

	
	Canny(img_gry, img_cny, threshold1, threshold2, kernel);

	imshow("Input Image", input_img);
	imshow("Canny Image", img_cny);
	waitKey(0);
}