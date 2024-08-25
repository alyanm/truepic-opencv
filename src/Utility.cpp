#include "../inc/Utility.h"

#include <filesystem>
#include <fstream>
#include <iostream>

#include <opencv2/core.hpp>

using namespace std;
using namespace cv;
namespace fs = filesystem;

/** Helpful utility functions. */
namespace Utility {

    /** Verify that OpenCV has been installed and is working. */
    void VerifyOpenCV()
    {
        Mat image = Mat::zeros(100, 100, CV_8UC3);
        if (image.empty()) {
            throw runtime_error("OpenCV not working, failed to create image!");
        }
    }

    /** Verify that given file exists and permissions allow access. */
    void CheckFileValidity(const string& fileName)
    {
        if (!fs::exists(fileName)) {
            throw runtime_error("Error: File does not exist: " + fileName);
        }

        // Check file permissions
        ifstream file(fileName);
        if (!file.good()) {
            throw runtime_error("Error: Cannot read file, check permissions: " + fileName);
        }
        file.close();
    }

    /** Display help message for the program. */
    void Help(const char* argv[])
    {
        cout << "\nThis program demonstrates the use of cv::CascadeClassifier class to detect objects (Face). You can use Haar or LBP features.\n"
            "Usage:\n"
            << argv[0]
            << "   [--cascade=<cascade_path> this is the primary trained classifier such as frontal face]\n"
            "   [filename]\n\n"
            "example:\n"
            << argv[0]
            << " --cascade=\"./haarcascades/haarcascade_frontalface_alt.xml\"\n\n"
            "During execution:\n\tHit any key to quit.\n"
            "\tUsing OpenCV version " << CV_VERSION << "\n" << endl;
    }
};