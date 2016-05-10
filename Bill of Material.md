Inter-Car Communication

About this file
This file describes the project structure and provides technical information of 

1.About project
This project contains four parts: Input, Object Detection(or Image Processing), Scenario Analysation and Communication. Input part does the preprocessing of the data like HDF5 and output the corresponding images. Objec

2.Technical information about project
(1)Programming Language:
Name:C++
Version:14
License:

(2)Build Tool:
Name:CMake
Version:3.5.2
License:BSD 3-clause License

(3)Plugins/Packages:
(a)Input(Messaging)
Name:HDF5
Version:1.10.0
License:BSD-style open source license

Name:Protocol Buffers
Version:2.6.1
License:3-clause BSD License

(b)Object Detection(Image Processing)
Name:Open CV
Version:2.4.3
License:3-clause BSD License

(c)Scenario Analysation
Plugins/Packages:
Name:
Version:
License:

(d)Communication
Name:
Version:
License:

3.Build process
What we have done
Make HDF5 work in Docker
An app, which make HDF5 API accessible and can be built in cmake
Build CMake of protobuf deserializer on Docker
Implement detection example work in Open CV
Communication between two processes with protobuf

Next Step
