#pragma once

#include <opencv2/core.hpp>
#include <string>
#include <iostream>

#include "easypr.h"


class PlateDetector {
  public:
    PlateDetector();
    ~PlateDetector();
    std::string Recognize(const cv::Mat &src);

  private:
    easypr::CPlateRecognize * pr_;
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

PlateDetector::~PlateDetector() {
  delete pr_;
}

std::string PlateDetector::Recognize(const cv::Mat &src) {
    plate_vec_.clear();
    int result = pr_->plateRecognize(src, plate_vec_);
    if (result == 0 && !plate_vec_.empty()) {
        return plate_vec_[0].getPlateStr();
    } else {
        return "";
    }
}
