<img src="https://travis-ci.org/JoHeinrich/amos-ss16-proj5.svg?branch=master">

# AMOS Project 2016 - Group 5
### Collision avoidance using object detection and inter-car communication

#### Summary:
This project will implement a scenario needed for autonomous driving with the help of software agents:
A bus stops at a bus stop vis-à-vis to a school. A car that drives behind the bus cannot see the children starting to run across the street in front of the bus. Another car on the other side of the street detects the children and is able to warn the first car.

<img src="https://rawgit.com/JoHeinrich/amos-ss16-proj5/master/info/overview.svg" alt="OverviewImage" width="500">

#### Main tasks: 
- Implement a simple object detection algorithm
- Integrate a software agent library
- Implement the scenario using software agents and inter-ECU (electronic control unit, i.e. car) communication

#### Setup:
- Operating System: Linux Ubuntu
- SW Agents library: CAF: C++ Actor Framework
- Library for detection: OpenCV
- Messaging format: HDF5, Google Protobuf

#### Docker image:
Try our Docker image and run this project without installing all dependencies. <br>
For installing Docker and pulling the image take a look at our  [wiki](https://github.com/JoHeinrich/amos-ss16-proj5/wiki/Dockerhub-HowTo).<br>
Use our [scripts](https://github.com/JoHeinrich/amos-ss16-proj5/tree/master/script) to start the programs.

#### Project dependencies:
- Min. CMake 2.8:  [Download](https://cmake.org/download/), [Install](https://cmake.org/install)
- HDF5: [Download & Install](https://www.hdfgroup.org/HDF5/release/cmakebuild.html#build)
- Google Protobuf 2.6.1: [Download](https://github.com/google/protobuf/releases/download/v2.6.1/protobuf-2.6.1.tar.gz), [Install]( https://github.com/google/protobuf/blob/master/src/README.md)
- Integrate OpenCV extra modules in OpenCV building: [Download](https://github.com/Itseez/opencv_contrib), [Install](https://github.com/Itseez/opencv_contrib)  `do this before building OpenCV!`
- OpenCV 3.1: [Download](http://opencv.org/downloads.html), [Install](http://docs.opencv.org/3.1.0/d7/d9f/tutorial_linux_install.html)
- CAF: C++ Actor Framework 0.14.5: [Download & Install] (https://github.com/actor-framework/actor-framework)
- A [OpenMP Compiler] (http://openmp.org/wp/openmp-compilers/)

#### Clone project: 
    $ git clone https://github.com/JoHeinrich/amos-ss16-proj5.git
    $ cd amos-ss16-proj5

#### Build command: 
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

#### Source code documentation:
See our [Doxygen site](http://joheinrich.github.io/amos-ss16-proj5-gh-pages/index.html)
