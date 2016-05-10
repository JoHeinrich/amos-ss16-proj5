# Inter-Car Communication

### About this file
This file describes the project structure and provides technical information of 

### About project
This project contains four parts: Input, Object Detection(or Image Processing), Scenario Analysation and Communication. Input part does the preprocessing of the data like HDF5 and output the corresponding images. Objec

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
Version:3.5.2
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
Version:2.4.3
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
Name:
Version:
License:
```
### Build process
##### What we have done
- Make HDF5 work in Docker
- An app, which make HDF5 API accessible and can be built in cmake
- Build CMake of protobuf deserializer on Docker
- Implement detection example work in Open CV
- Communication between two processes with protobuf

##### Next Step
