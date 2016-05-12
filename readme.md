<img src="https://travis-ci.org/JoHeinrich/amos-ss16-proj5.svg?branch=master">

# AMOS Project 2016 - Group 5
### Collision avoidance using object detection and inter-car communication

#### Summary:
This project will implement a scenario needed for autonomous driving with the help of software agents:
A bus stops at a bus stop vis-à-vis to a school. A car that drives behind the bus cannot see the children starting to run across the street in front of the bus. Another car on the other side of the street detects the children and is able to warn the first car.

#### Main tasks: 
- Implement a simple object detection algorithm
- Integrate a software agent library
- Implement the scenario using software agents and inter-ECU (electronic control unit, i.e. car) communication

#### Setup:
- Operating System: Linux Ubuntu
- SW Agents library: Mobile-C
- Library for detection: OpenCV
- Messaging format: HDF5, Google Protobuf

#### Download and install dependencies:
- Min. CMake 2.8:  [Download](https://cmake.org/download/), [Install](https://cmake.org/install)
- HDF5: [Download & Install](https://www.hdfgroup.org/HDF5/release/cmakebuild.html#build)
- Google Protobuf 2.6.1: [Download](https://github.com/google/protobuf/releases/download/v2.6.1/protobuf-2.6.1.tar.gz), [Install]( https://github.com/google/protobuf/blob/master/src/README.md)
- Integrate OpenCV extra modules in OpenCV building: [Download](https://github.com/Itseez/opencv_contrib), [Install](https://github.com/Itseez/opencv_contrib)  `do this before building OpenCV!`
- OpenCV 3.1: [Download](http://opencv.org/downloads.html), [Install](http://docs.opencv.org/3.1.0/d7/d9f/tutorial_linux_install.html)


#### Build Command: 
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
