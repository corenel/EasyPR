#include <chrono>
#include "wrapper.h"

int main(int argc, const char *argv[]) {
  if (argc == 1) {
    return -1;
  }

  std::string filename = argv[1];
  cv::Mat src = imread(filename);
  PlateDetector pd;

  auto begin = std::chrono::steady_clock::now();
  std::string license = pd.RecognizeAll(src);
  auto end = std::chrono::steady_clock::now();

  if (license != "") {
    std::cout << license << std::endl;
  } else {
    std::cout << "license plate is not detected." << std::endl;
  }

  std::cout << "Duration = "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     begin)
                   .count()
            << "ms" << std::endl;
  std::cout << "Duration = "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     begin)
                   .count()
            << "us" << std::endl;
  std::cout << "Duration = "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin)
                   .count()
            << "ns" << std::endl;
  return 0;
}
