cmake_minimum_required(VERSION 3.1.0)
project(thirdparty)

# c++11 required
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-pg")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# OpenVC3 required
find_package(OpenCV 3.1.0 REQUIRED)

# where to find header files
include_directories(.)
include_directories(include)
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
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}
    stdc++
    ${OpenCV_LIBS}
    )
