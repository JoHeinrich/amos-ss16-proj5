# AMOS Project 2016 - Group 5
### Script Usage Guide

#### General
This scripts are bound to change with the continued progress we make in this project. We will try to keep this readme up to date though! If the scripts don't work, try to pull the most recent docker image from our dockerhub!

#### Amos-SS16-Proj5 -- the main program
This script starts our main program that consists of a hdf5/mp4 stream decoder, an object detection, scenario analyzation, and a client-server communication via the C++ Actor Framework. It needs to be run with a docker container tag, the full path to either an mp4 or hdf5 encoded video stream, the name of a docker network and the port the server and client should work on:

$ script/amos-ss16-proj5.sh _CONTAINER_TAG_  _FULL_PATH_TO_FILE_  _NAME_OF_NETWORK_  _PORT_


Now, you should be able to see object detection for cars and humans in the specified video as well as communication between the client and server.


