#pragma once

#include <opencv2/core.hpp>
#include <string>
#include <iostream>

#include "easypr.h"

std::string Recognize(const cv::Mat &src) {
    easypr::CPlateRecognize pr;
    pr.setResultShow(false);
    pr.setDetectType(easypr::PR_DETECT_COLOR | easypr::PR_DETECT_SOBEL | easypr::PR_DETECT_CMSER);
    pr.setLifemode(true);
    pr.setMaxPlates(1);

    vector<easypr::CPlate> plate_vec;
    int result = pr.plateRecognize(src, plate_vec);
    if (result == 0) {
        return plate_vec[0].getPlateStr();
    } else {
        return "";
    }
}
