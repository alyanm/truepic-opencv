#include "Utility.h"

#include <filesystem>
#include <fstream> // Include fstream for file operations
#include <iostream>

#include <opencv2/core.hpp>

using namespace std;
using namespace cv;
namespace fs = filesystem;

namespace Utility {
    void VerifyOpenCV()
    {
        Mat image = Mat::zeros(100, 100, CV_8UC3);
        if (image.empty()) {
            throw runtime_error("OpenCV not working, failed to create image!");
        }
    }

    void CheckFileValidity(const string& imagePath)
    {
        if (!fs::exists(imagePath)) {
            throw runtime_error("Error: File does not exist: " + imagePath);
        }

        // Check file permissions
        ifstream file(imagePath);
        if (!file.good()) {
            throw runtime_error("Error: Cannot read file, check permissions: " + imagePath);
        }
        file.close();
    }

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