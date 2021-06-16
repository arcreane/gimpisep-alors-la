#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <string>
using namespace std;
using namespace cv;

void lighten_darken(string filename, double factor)
{   
    Mat image = imread(filename);
    Mat new_image = Mat::zeros(image.size(), image.type());
    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            for (int c = 0; c < 3; c++) {
                new_image.at<Vec3b>(y, x)[c] =
                    saturate_cast<uchar>((image.at<Vec3b>(y, x)[c]) + factor);
            }
        }
    }
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    namedWindow("New Image", WINDOW_AUTOSIZE);
    imshow("Original Image", image);
    imshow("New Image", new_image);
    waitKey();
}


