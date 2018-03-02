#include "wrapper.h"
#include <chrono>


int main(int argc, const char *argv[]) {
    if (argc == 1) {
        return -1;
    }

    std::string filename = argv[1];
    cv::Mat src = imread(filename);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::string license = Recognize(src);
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << license << std::endl;
    std::cout << "Duration = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" <<std::endl;
    std::cout << "Duration = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "us" <<std::endl;
    std::cout << "Duration = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "ns" <<std::endl;
    return 0;
}

