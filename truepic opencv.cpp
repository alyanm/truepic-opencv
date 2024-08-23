// truepic opencv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

int main(int argc, char * argv[])
{
    if (argc < 2) // Check if an argument is provided
    {
        std::cerr << "Usage: " << argv[0] << " <path_to_image>" << std::endl;
        return -1;
    }

    cv::Mat img = cv::imread("test.jpg", 0);
    if (img.empty()) {
        std::cerr << "Error loading image!" << std::endl;
        return 1;
    }

    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    cv::imshow("First OpenCV Application", img);
    cv::moveWindow("First OpenCV Application", 0, 45);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
