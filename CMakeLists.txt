cmake_minimum_required(VERSION 3.0.0)
project(easypr)

# c++11 required
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/usr/local/opt/opencv-3.2.0")
endif ()

# OpenVC3 required
find_package(OpenCV 3.2.0 REQUIRED)

# where to find header files
include_directories(.)
include_directories(include)
include_directories(${OpenCV_INCLUDE_DIRS})

# sub directories
add_subdirectory(thirdparty)

# sources to be compiled
set(SOURCE_FILES
        src/core/core_func.cpp
        src/core/chars_identify.cpp
        src/core/chars_recognise.cpp
        src/core/chars_segment.cpp
        src/core/feature.cpp
        src/core/plate_detect.cpp
        src/core/plate_judge.cpp
        src/core/plate_locate.cpp
        src/core/plate_recognize.cpp
        src/core/params.cpp

        src/train/ann_train.cpp
        src/train/annCh_train.cpp
        src/train/svm_train.cpp
        src/train/train.cpp
        src/train/create_data.cpp

        src/util/util.cpp
        src/util/program_options.cpp
        src/util/kv.cpp
        )

# pack objects to static library
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".so")
endif ()
target_link_libraries(${PROJECT_NAME}
    stdc++
    ${OpenCV_LIBS}
    thirdparty
    )

# test cases
set(EXECUTABLE_NAME "plate_detector")
add_executable(${EXECUTABLE_NAME} python/wrapper.cpp)
target_link_libraries(${EXECUTABLE_NAME}
    stdc++
    ${OpenCV_LIBS}
    thirdparty
    ${PROJECT_NAME}
    )
# set_target_properties(${PROJECT_NAME}_test
#     PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/../")
