#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/stitching.hpp>
#include <opencv2/imgcodecs.hpp>
#include<iostream>
#include <string>
#include <filesystem>
#include"resizing.h"
#include"panorama.h"
using namespace std;
using namespace cv;

int main()
{
    cout << "Hello World" << endl;

    //resizing("HappyFish.jpg", 2, 2);
    panorama("Pano");
    return 0;
}
