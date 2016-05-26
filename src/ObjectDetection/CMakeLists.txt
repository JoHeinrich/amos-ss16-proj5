cmake_minimum_required(VERSION 2.8)
project( humandetection )
find_package( OpenCV )
# Provide the include directories to the caller
SET(OpenCV_INCLUDE_DIRS "/home/travis/build/JoHeinrich/amos-ss16-proj5/docker/assets/openCV/include/opencv2;/home/travis/build/JoHeinrich/amos-ss16-proj5/docker/assets/openCV/include")
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( humandetection humandetector.cpp )
target_link_libraries( humandetection ${OpenCV_LIBS} )
