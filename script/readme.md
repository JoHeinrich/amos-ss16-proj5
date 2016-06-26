# AMOS Project 2016 - Group 5
### Script Usage Guide

#### General
This scripts are bound to change with the continued progress we make in this project. We will try to keep this readme up to date though! If the scripts don't work, try to pull the most recent docker image from our dockerhub!

#### Caf Communication
The communication with the C++ Actor Framework consists of 2 scripts, which implement a client and server model. Start the scripts in separate terminals like this:

$ script/ubuntuCafClient.sh.sh _NETWORK_NAME_  _DOCKER_CONTAINER_TAG_

$ script/ubuntuCafServer.sh.sh _NETWORK_NAME_  _DOCKER_CONTAINER_TAG_

Now the server should receive a warning from the client na acknowledge it.

#### Stream Decoder
The stream decoder reads one given or all frames from a specified HDF-File. Start the script like this:

$ script/ubuntuStreamDecoder.sh _FULL_PATH_TO_HDF5_FILE_ _DOCKER_CONTAINER_TAG_ [optional: _FRAME_INDEX_ ]

You should see an image of the specified frame.
