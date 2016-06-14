# Inter-Car Communication

### About this file
This file provides the basic information about project structure, technical tools, third party software and the build process.

### About project
This project contains four parts: Input(or Messaging), Object Detection(or Image Processing), Scenario Analysation and Communication. Input part does the preprocessing of the data like HDF5 and output the corresponding images. Object Detection part gives out the spatial information of detected objects. Scenario Analysation part chooses the appropriate scene for further analysations. Communication part does the information exchanging between cars.

### Technical information about project
##### Programming Language:

```sh
Name:C++
Version:14
License:
```

##### Build Tool:

```sh
Name:CMake
Version:2.8
License:BSD 3-clause License
```

##### Plugins/Packages:

###### Input(Messaging)
```sh
Name:HDF5
Version:1.10.0
License:BSD-style open source license
```
```sh
Name:Protocol Buffers
Version:2.6.1
License:3-clause BSD License
```

###### Object Detection(Image Processing)
```sh
Name:Open CV
Version:3.1
License:3-clause BSD License
```
###### Scenario Analysation
```sh
Name:
Version:
License:
```
###### Communication
```sh
Name: CAF: C++ Actor Framework
Version: 0.14
License: Boost Software License - Version 1.0
```
### Build process
##### What we have done
- Make HDF5 work in Docker
- An app, which make HDF5 API accessible and can be built in cmake
- Build CMake of protobuf deserializer on Docker
- Implement detection example work in Open CV
- Communication between two processes with protobuf

##### Next Step

#### Release Information
##### sprint-05-release
##### mid-term-release
Main progress in ..., user stories ... added.
