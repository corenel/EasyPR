#!/usr/bin/env bash
echo "generate wrapper by swig..."
swig -I../opencv-swig/lib -I/usr/local/include -python -c++ wrapper/plate_detector.i
echo "generate shared library by g++..."
g++ -shared -fpic wrapper/plate_detector_wrap.cxx \
  -Iinclude -Isrc -Iwrapper \
  -Lbuild -Lbuild/thirdparty -leasypr -lthirdparty \
  $(pkg-config --cflags --libs python3) $(pkg-config --libs opencv) \
  --std=c++11 \
  -o wrapper/_plate_detector.so
echo "copy libeasypr and libthirdparty..."
cp build/libeasypr.so wrapper
cp build/thirdparty/libthirdparty.so wrapper
echo "link model..."
ln -s ../model/ wrapper
