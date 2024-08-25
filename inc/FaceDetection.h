#pragma once

#include <string>

#include <opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>

class FaceDetection
{
public:
    FaceDetection(const std::string inputName, const std::string cascadeName);
    void detectFacesAndDisplay();

private:
    cv::Mat img;
    cv::CascadeClassifier faceCascade;
};
