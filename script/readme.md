# AMOS Project 2016 - Group 5
### Script Usage Guide

#### General
This scripts are bound to change with the continued progress we make in this project. We will try to keep this readme up to date though! If the scripts don't work, try to pull the most recent docker image from our dockerhub!

#### Communication
The communication consists of 2 scripts, which implement a client and server model. Start the scripts in separate terminals like this:

$ script/ubuntuCommunicationServer.sh _NETWORK_NAME_  _DOCKER_CONTAINER_TAG_

$ script/ubuntuCommunicationClient.sh _network_name_  _DOCKER_CONTAINER_TAG_

Now the server should receive a warning from the client.

#### Stream Decoder
The stream decoder reads one given or all frames from a specified HDF-File. Start the script like this:

$ script/ubuntuStreamDecoder.sh _FULL_PATH_TO_HDF5_FILE_ _DOCKER_CONTAINER_TAG_ [optional: _FRAME_INDEX_ ]

You should see an image of the specified frame.

#### Human Detection
The human detection program recognizes humans in a given video file. Start the script like this:

$ script/ubuntuVideo.sh _FULL_PATH_TO_TEST_VIDEO_ _DOCKER_CONTAINER_TAG_

You should see the video with live detection of any human beings. Note: The program has to be closed with STRG+C right now if you are a linux user.
