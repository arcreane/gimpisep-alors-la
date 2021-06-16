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

    resize(img, newimg, (newimg).size(), fx, fy,INTER_LINEAR);

    imwrite("resized_image.jpg", newimg);

    namedWindow("Original Image", WINDOW_AUTOSIZE);
    namedWindow("New Image", WINDOW_AUTOSIZE);
    imshow("Original Image", img);
    imshow("New Image", newimg);
    waitKey();

}

void panorama(string directory) 
{
    vector<Mat> imgs;

    vector<string> filenames;
    string path = directory + "/*.jpg";
    glob(path, filenames, false);

    vector<string>::iterator it;
    for (it = filenames.begin(); it != filenames.end(); ++it)
    {
        imgs.push_back(imread(*it, IMREAD_COLOR));
    }

    
    Stitcher::Mode mode = Stitcher::PANORAMA;

    Mat pano;
    Ptr<Stitcher> stitcher = Stitcher::create(mode);
    Stitcher::Status status = stitcher->stitch(imgs, pano);

    string result_img = "panoramized_image.png";

    imwrite(result_img, pano);
}

int main()
{
    resizing("HappyFish.jpg", 2, 2);
    //panorama("Pano");
    return 0;
}