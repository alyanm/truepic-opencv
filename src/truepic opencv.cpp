// truepic opencv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <filesystem>
#include <fstream> // Include fstream for file operations
#include <iostream>

#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include "../inc/truepic opencv.h"
#include "../inc/Utility.h"
#include "../inc/FaceDetection.h"

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

        string cascadeFileName = parser.get<string>("cascade");
        string imageFileName = parser.get<string>("@filename");
        if (imageFileName.empty()) {
            imageFileName = imagePath;
        }

        FaceDetection faceDetect = FaceDetection(imageFileName, cascadeFileName);
        faceDetect.detectFacesAndDisplay();
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


