#include "../inc/FaceDetection.h"
#include "../inc/Utility.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace Utility;

using namespace cv;
using namespace std;

/** Face Detection implementation using OpenCV with Haar Cascades
    pre constructed ML model for facial detection of image.
    This constructor will load up the specified image from file and also
    load up the Haar cascade ML model from a file. */
FaceDetection::FaceDetection(const string imageFileName, const string haarCascadeFileName) {
    CheckFileValidity(imageFileName);
    CheckFileValidity(haarCascadeFileName);
    VerifyOpenCV();

    this->img = imread(imageFileName, IMREAD_COLOR);
    if (img.empty()) {
        throw runtime_error("Error loading image: " + imageFileName);
    }

    // Load the Haar Cascade

    if (!faceCascade.load(haarCascadeFileName)) {
        throw runtime_error("Error loading cascade file: " + haarCascadeFileName);
    }
}

/** Detect faces in the image and display the result */
void FaceDetection::detectFacesAndDisplay() {
    vector<cv::Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 3, 0, Size(30, 30));

    // Draw rectangles around detected faces
    for (const auto& face : faces) {
        rectangle(img, face, Scalar(255, 0, 0), 2);
    }

    // Display the result
    namedWindow("Detected Faces", cv::WINDOW_AUTOSIZE);
    imshow("Detected Faces", img);
    waitKey(0);
}