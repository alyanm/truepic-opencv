// truepic opencv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <filesystem>
#include <fstream> // Include fstream for file operations
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;
namespace fs = std::filesystem;

int main(int argc, char * argv[])
{
    try {
        string imagePath = "C:\\Users\\almoo\\source\\repos\\truepic_opencv\\test.jpg";
        // Debugging output to verify the file path
        cout << "Attempting to load image from path: " << imagePath << endl;

        if (!fs::exists(imagePath)) {
            cerr << "Error: File does not exist!" << endl;
            return 1;
        }

        // Check file permissions
        ifstream file(imagePath);
        if (!file.good()) {
            cerr << "Error: Cannot read file, check permissions!" << endl;
            return -1;
        }
        file.close();

        Mat img = Mat::zeros(100, 100, CV_8UC3);
        if (img.empty()) {
            cerr << "Failed to create image!" << endl;
            return -1;
        }
        cout << "OpenCV is working correctly!" << endl;

        //IplImage* img = CvLoadImage("2_DeepViewOutput.png");
        
        img = imread(imagePath, 0);
        if (img.empty()) {
            cerr << "Error loading image!" << std::endl;
            return -1;
        }

        namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
        imshow("First OpenCV Application", img);
        moveWindow("First OpenCV Application", 0, 45);
        waitKey(0);
        destroyAllWindows();
    }
    catch (const Exception& e) {
        cerr << "OpenCV error: " << e.what() << endl;
        return -1;
    }
    catch (const exception& e) {
        cerr << "Standard exception: " << e.what() << endl;
        return -1;
    }
    catch (...) {
        cerr << "Unknown error occurred!" << endl;
        return -1;
    }

    return 0;
}