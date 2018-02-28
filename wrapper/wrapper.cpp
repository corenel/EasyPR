#include "wrapper.h"


int main(int argc, const char *argv[]) {
    if (argc == 1) {
        return -1;
    }

    std::string filename = argv[1];
    cv::Mat src = imread(filename);
    std::string license = Recognize(src);
    std::cout << license << std::endl;
    return 0;
}

