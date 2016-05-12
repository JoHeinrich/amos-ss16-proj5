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

1. Download and install CMake:  
	▪ Download:     https://cmake.org/download/  	
	▪ Installation:	https://cmake.org/install
    
2. Build HDF5 library with CMake:  
	▪	https://www.hdfgroup.org/HDF5/release/cmakebuild.html#build

3. Download and build google protopuf
    ▪ Download:     https://github.com/google/protobuf/releases/download/v2.6.1/protobuf-2.6.1.tar.gz
    ▪ Installation: https://github.com/google/protobuf/blob/master/src/README.md


Build Command: 
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

Run Command:
    $ ./AutoDrive
