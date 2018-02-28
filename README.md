# Python binding for EasyPR
 This repo contains a python binding for the original [EasyPR](https://github.com/liuruoze/EasyPR) C++ library.
 
 ## Environment
 This version of python binding is only tested on Ubuntu 16.04.3 LTS with OpenCV 3.3.1 .
 
 ## Usage
 1. Download and unpack python module with shaerd library from [Release Page](https://github.com/corenel/EasyPR/releases).
 2. Demo code:
 ```python
>>> import plate_detector
>>> import cv2
>>> im = cv2.imread(path_to_test_image)
>>> imp = plate_detector.Mat.from_array(im)
>>> plate_detector.Recognize(imp)
'蓝牌:津AJ0W96'
```

## Customize
1. Modify `wrapper/wrapper.h` as what you like.
2. Run `build_shared_objects.sh` to generate `libeasypr.so` and `libthirdparty.so`
3. Run `build_python_binding.sh` to generate python binding `plate_detector.py` and `_plate_detector.so`
