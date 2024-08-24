// truepic opencv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <filesystem>
#include <fstream> // Include fstream for file operations
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include "truepic opencv.h"
#include "Utility.h"
using namespace Utility;

using namespace cv;
using namespace std;
namespace fs = filesystem;

int main(int argc, const char * argv[])
{
    try {
        const string imagePath = "boy.jpg";

        CommandLineParser parser(argc, argv,
            "{help h||}"
            "{cascade|..\\..\\haarcascades/haarcascade_frontalface_alt.xml|}"
            "{@filename|boy.jpg|}"
        );
        if (parser.has("help"))
        {
            Help(argv);
            return 0;
        }

        string cascadeName = parser.get<string>("cascade");
        string inputName = parser.get<string>("@filename");
        if (inputName.empty()) {
            inputName = imagePath;
        }

        CheckFileValidity(inputName);
        CheckFileValidity(cascadeName);
        VerifyOpenCV();
        
        Mat img = imread(inputName, IMREAD_COLOR);
        if (img.empty()) {
            throw runtime_error("Error loading image: " + inputName);
        }

        // Load the Haar Cascade
        CascadeClassifier faceCascade;
        if (!faceCascade.load(cascadeName)) {
            throw runtime_error("Error loading cascade file: " + cascadeName);
        }

        // Convert the image to grayscale
        Mat gray;
        cout << "Convert image to grayscale" << endl;
        cvtColor(img, gray, COLOR_BGR2GRAY);

        // Detect faces
        vector<cv::Rect> faces;
        faceCascade.detectMultiScale(img, faces, 1.1, 3, 0, Size(30, 30));

        // Draw rectangles around detected faces
        for (const auto& face : faces) {
            rectangle(img, face, Scalar(255, 0, 0), 2);
        }

        // Display the result
        cv::namedWindow("Detected Faces", cv::WINDOW_AUTOSIZE);
        cv::imshow("Detected Faces", img);
        cv::waitKey(0);
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


