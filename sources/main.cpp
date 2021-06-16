#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <string>
#include "lighten_darken.h"
#include "canny_edge_detection.h"
using namespace std;
using namespace cv;

double factor;
int choice;
double threshold1;
double threshold2;
double kernel;
int userChoice;

int main() {

    cout << "Welcome to our image editor \n What would you like to do with your image ? \n Type in the corresponding number \n 1. Dilatation/Erosion\n 2. Resizing\n 3. Lighten/Darken\n 4. Panorama/Stitching\n 5. Canny edge detection\n 0. Quit"<< endl;
    cin >> userChoice;

    if (userChoice == 3) {
        cout << "Type 0 if you want to lighten the image, 1 if you want to darken it" << endl;
        cin >> choice;
        if (choice == 0) {
            cout << "Type in the desired enlightening factor (between 0 and 256)" << endl;
            cin >> factor;
            while (factor > 256 or factor < 0) {
                cout << "The factor should be between 0 and 256. Please try again" << endl;
                cin >> factor;
            }
            lighten_darken("HappyFish.jpg", factor);
        }

        if (choice == 1) {
            cout << "Type in the desired darkening factor (between 0 and 256)" << endl;
            cin >> factor;
            while (factor > 256 or factor < 0) {
                cout << "The factor should be between 0 and 256. Please try again :" << endl;
                cin >> factor;
            }
            lighten_darken("HappyFish.jpg", -factor);
        }    
    }
    

    if (userChoice == 5) {
        cout << "Canny edge detection \n Please enter the first threshold :" << endl;
        cin >> threshold1;

        cout << "Please enter the second threshold" << endl;
        cin >> threshold2;

        cout << "Please enter the kernel value" << endl;
        cin >> kernel;

        canny_edge_detection("HappyFish.jpg", threshold1, threshold2, kernel);
    }

    return 0;
}