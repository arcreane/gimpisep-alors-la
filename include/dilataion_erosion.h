
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

int dilatation_erosion(string filename, int size) {
    Mat image = imread(filename, IMREAD_COLOR);
    Mat erodedimage;
    erode(image, erodedimage, getStructuringElement(MORPH_RECT, Size(size, size)));
    String window_name = "Photo non-modifiée";
    String window_name_erodedimage = "Image érodée";
    namedWindow(window_name);
    namedWindow(window_name_erodedimage);
    imshow(window_name, image);
    imshow(window_name_erodedimage, erodedimage);
    

    Mat dilatedimage;
    dilate(image, dilatedimage, getStructuringElement(MORPH_RECT, Size(size, size)));
    String window_name_dilatedimage = "Image dilatée";
    namedWindow(window_name_erodedimage);
    imshow(window_name_dilatedimage, dilatedimage);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
