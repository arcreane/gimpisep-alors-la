#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/stitching.hpp>
#include <opencv2/imgcodecs.hpp>
#include<iostream>
#include <string>
#include <filesystem>
using namespace std;
using namespace cv;

void panorama(string directory)
{
    vector<Mat> imgs;

    vector<cv::String> filenames = { "half1.jpg","half2.jpg" };


    for (auto & filename : filenames)
    {
        imgs.push_back(imread(samples::findFile(filename)));
    }


    Stitcher::Mode mode = Stitcher::PANORAMA;

    Mat pano;
    Ptr<Stitcher> stitcher = Stitcher::create(mode);
    Stitcher::Status status = stitcher->stitch(imgs, pano);

    string result_img ("panoramized_image.png");

    imwrite(result_img, pano);

    namedWindow("New Image", WINDOW_AUTOSIZE);
    imshow("New Image", pano);
    waitKey();

}


