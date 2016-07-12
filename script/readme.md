# AMOS Project 2016 - Group 5
### Script Usage Guide

#### General
These scripts are bound to change with the continued progress we make in this project. We will try to keep this readme up to date though! If the scripts don't work, try to pull the most recent docker image from our dockerhub!

#### Amos-SS16-Proj5 -- the main program
This script starts our main program that consists of a hdf5/mp4 stream decoder, an object detection, scenario analyzation, and a client-server communication via the C++ Actor Framework. The script offers a simple gui to enter a docker container tag and the name of a docker network. Afterwards you can choose either an mp4 or hdf5 file to run our program with. Start it like this:

$ bash script/amos-ss16-proj5-gui.sh

Alternatively, you can enter the parameters via the command line, using the amos-ss16-proj5.sh. 

$ bash script/amos-ss16-proj5.sh _CONTAINER_TAG_  _FULL_PATH_TO_FILE_  _NAME_OF_NETWORK_  _PORT_

For showcasing purposes, there's also the script version we used for the demo. It works like the gui version of our script above except it uses the release tag of our docker image automatically and allows you to pick multiple video files from the file explorer, which will be played consequently. Start the script like this:

$ demo-amos-ss16-proj5-gui.sh

Now, you should be able to see object detection for cars and humans in the specified video as well as communication between the client and server.


