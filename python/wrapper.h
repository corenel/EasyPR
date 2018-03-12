#pragma once

#include <iostream>
#include <opencv2/core.hpp>
#include <string>

#include "easypr.h"

class PlateDetector {
 public:
  PlateDetector();
  ~PlateDetector();
  void SetDetectType(const int &type);
  std::string Recognize(const cv::Mat &src);
  std::string RecognizeAll(const cv::Mat &src);

 private:
  easypr::CPlateRecognize *pr_;
  vector<easypr::CPlate> plate_vec_;
};

PlateDetector::PlateDetector() {
  pr_ = new easypr::CPlateRecognize;
  pr_->setResultShow(false);
  // pr_->setDetectType(easypr::PR_DETECT_COLOR | easypr::PR_DETECT_SOBEL);
  pr_->setDetectType(easypr::PR_DETECT_CMSER);
  pr_->setLifemode(true);
  pr_->setMaxPlates(1);
}

PlateDetector::~PlateDetector() { delete pr_; }

std::string PlateDetector::Recognize(const cv::Mat &src) {
  plate_vec_.clear();
  int result = pr_->plateRecognize(src, plate_vec_);
  if (result == 0 && !plate_vec_.empty()) {
    return plate_vec_[0].getPlateStr();
  } else {
    return "";
  }
}

void PlateDetector::SetDetectType(const int &type) {
  if (!pr_) {
    std::cout << "PlateDetector is not initialized." << std::endl;
    return;
  }
  switch (type) {
    case 0:
      // std::cout << "use COLOR & SOBEL for plate detection" << std::endl;
      pr_->setDetectType(easypr::PR_DETECT_COLOR | easypr::PR_DETECT_SOBEL);
      break;
    case 1:
      // std::cout << "use CMSER for plate detection" << std::endl;
      pr_->setDetectType(easypr::PR_DETECT_CMSER);
      break;
    case 2:
      // std::cout << "use COLOR & SOBEL & CMSER for plate detection" << std::endl;
      pr_->setDetectType(easypr::PR_DETECT_COLOR | easypr::PR_DETECT_SOBEL |
                         easypr::PR_DETECT_CMSER);
      break;
    default:
      std::cout << "invalid type for plate detection" << std::endl;
      break;
  }
}

std::string PlateDetector::RecognizeAll(const cv::Mat &src) {
  for (auto i = 0; i < 3; ++i) {
    SetDetectType(i);
    std::string license = Recognize(src);
    if (license != "") {
      return license;
    }
  }
}
