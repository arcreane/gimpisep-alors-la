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

   vector<string> filenames;
    string path = directory + "/*.jpg";
    glob(path, filenames, false);

    vector<string>::iterator it;
    for (it = filenames.begin(); it != filenames.end(); ++it)
    {
        Mat new_img;
        new_img = imread(*it, IMREAD_COLOR);
        imgs.push_back(new_img);
    }


    Stitcher::Mode mode = Stitcher::PANORAMA;

    Mat pano;
    Ptr<Stitcher> stitcher = Stitcher::create(mode);
    Stitcher::Status status = stitcher->stitch(imgs, pano);

    string result_img ("panoramized_image.png");

    namedWindow("New Image", WINDOW_AUTOSIZE);
    imshow("New Image", pano);
    waitKey();
    
    imwrite(result_img, pano);

}


