#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <string>
using namespace std;
using namespace cv;

void canny_edge_detection(string filename, double threshold1, double threshold2, double kernel)
{
	cv::Mat input_img, img_gry, img_cny;

	cv::namedWindow("Input Image", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Canny Image", cv::WINDOW_AUTOSIZE);

	input_img = cv::imread(filename);

	img_cny.create(input_img.size(), input_img.type());
	//destination img sholud be of same size & type as source img

	cv::cvtColor(input_img, img_gry, cv::COLOR_BGR2GRAY);
	//used to convert to gray image

	cv::Canny(img_gry, img_cny, threshold1, threshold2, kernel);

	cv::imshow("Input Image", input_img);
	cv::imshow("Canny Image", img_cny);
	cv::waitKey(0);
}