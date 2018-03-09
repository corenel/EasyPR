#!/usr/bin/env bash
# echo 'install dependencies'
# sudo apt-get install -y swig libboost-dev

echo "generate wrapper by swig..."
swig -I../opencv-swig/lib -I/usr/local/include -python -c++ python/plate_detector.i

echo "generate shared library by g++..."
g++ -shared -fpic python/plate_detector_wrap.cxx \
  -Iinclude -Isrc -Iwrapper \
  -Lbuild -Lbuild/thirdparty -leasypr -lthirdparty \
  $(pkg-config --cflags --libs python3) $(pkg-config --libs opencv) \
  --std=c++11 -Wall -O2 \
  -o python/_plate_detector.so

# echo "add libeasypr and libthirdparty to path..."
# cp build/libeasypr.so python
# cp build/thirdparty/libthirdparty.so python
# export LD_LIBRARY_PATH=$(pwd)/python:$LD_LIBRARY_PATH 
# echo "export LD_LIBRARY_PATH=$(pwd)/python:\$LD_LIBRARY_PATH" >> $HOME/.zshrc  # or .bashrc

# echo "link model..."
# ln -s model python

# echo "install python package..." 
# pip install -e python
