#include "easypr.h"
#include "accuracy.hpp"
#include "chars.hpp"
#include "plate.hpp"


int main(int argc, const char *argv[]) {
    easypr::CPlateRecognize pr;
    pr.setResultShow(false);
    pr.setDetectType(easypr::PR_DETECT_CMSER);

    if (argc == 1) {
        return -1;
    }

    std::string filename = argv[1];
    cv::Mat src = imread(filename);
    vector<easypr::CPlate> plate_vec;
    int result = pr.plateRecognize(src, plate_vec);
    if (result == 1) {
        std::for_each(plate_vec.begin(), plate_vec.end(), [](easypr::CPlate &plate) {
//            cv::Mat plate_mat = plate.getPlateMat();
//            cv::RotatedRect rect = plate.getPlatePos();
            string license = plate.getPlateStr();
            std::cout << license << std::endl;
        });
    }
    return 0;
}
