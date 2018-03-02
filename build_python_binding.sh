#!/usr/bin/env bash
echo 'install dependencies'
sudo apt-get install -y swig libboost-dev

echo "generate wrapper by swig..."
swig -I../opencv-swig/lib -I/usr/local/include -python -c++ wrapper/plate_detector.i

echo "generate shared library by g++..."
g++ -shared -fpic wrapper/plate_detector_wrap.cxx \
  -Iinclude -Isrc -Iwrapper \
  -Lbuild -Lbuild/thirdparty -leasypr -lthirdparty \
  $(pkg-config --cflags --libs python3) $(pkg-config --libs opencv) \
  --std=c++11 \
  -o wrapper/_plate_detector.so

echo "add libeasypr and libthirdparty to path..."
cp build/libeasypr.so wrapper
cp build/thirdparty/libthirdparty.so wrapper
export LD_LIBRARY_PATH=$(pwd)/wrapper:$LD_LIBRARY_PATH 
echo "export LD_LIBRARY_PATH=$(pwd)/wrapper:\$LD_LIBRARY_PATH" >> $HOME/.zshrc  # or .bashrc

# echo "link model..."
# ln -s ../model/ wrapper

echo "install python package..." 
pip install -e wrapper
