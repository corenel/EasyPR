#!/usr/bin/env bash

rm -rf build
mkdir build
cd build
cmake ..
make -j8

cp build/libeasypr.so python
cp build/thirdparty/libthirdparty.so python
