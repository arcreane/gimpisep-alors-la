#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/stitching.hpp>
#include <opencv2/imgcodecs.hpp>
#include<iostream>
#include <string>
#include <filesystem>
using namespace std;
using namespace cv;


void resizing(string filename, double fx, double fy)
{
    Mat img = cv::imread(filename, IMREAD_COLOR);
    Mat newimg;

    resize(img, newimg, (newimg).size(), fx, fy, INTER_LINEAR);

    imwrite("resized_image.jpg", newimg);

    namedWindow("Original Image", WINDOW_AUTOSIZE);
    namedWindow("New Image", WINDOW_AUTOSIZE);
    imshow("Original Image", img);
    imshow("New Image", newimg);
    waitKey();

}

