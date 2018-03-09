cmake_minimum_required(VERSION 3.1.0)
project(thirdparty)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-pg")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# OpenVC3 required
find_package(OpenCV 3.1.0 REQUIRED)

# where to find header files
include_directories(${OpenCV_INCLUDE_DIRS})

# sources to be compiled
set(SOURCE_FILES
        xmlParser/xmlParser.cpp
        textDetect/erfilter.cpp
        LBP/helper.cpp
        LBP/lbp.cpp
        mser/mser2.cpp
        )

# pack objects to static library
add_library(thirdparty SHARED ${SOURCE_FILES})
