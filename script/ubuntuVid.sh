#!/bin/bash
# Script for easier docker usage
set -e
echo -en '\n'
echo "Ubuntu Bash Start Script"
echo "This script will start our docker container. Please give the path to a test video and the tag for the docker image you want to start."
echo -en '\n'
if [ ! -f $1 ] || [ $# -lt 2 ]; then
  echo -en '\n'
  echo "Wrong Usage. Usage: ubuntuVideo.sh [ _FULL_PATH_TO_TEST_VIDEO_ ] [ _CONTAINER_TAG_ ]"
  echo "Whitespaces in the path are not allowed!"
  echo "Example: script/ubuntuVideo.sh /home/testVid.mp4 v1"
  exit
fi
echo "Configuring xhost"
xhost +local:
echo -en '\n'
echo "Starting the container now. All binaries can be found in /home/bin. The test video is mapped into the home directory."
#docker run -ti -v $1:/home/testVid.mp4 -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -e LD_LIBRARY_PATH=/home/openCV/lib:$LD_LIBRARY_PATH amosproj5/amosbuildimage:$2 /bin/bash
docker run -ti -v $1:/home/testVid.mp4 -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -e LD_LIBRARY_PATH=/home/openCV/lib:$LD_LIBRARY_PATH amosproj5/amosbuildimage:$2 /bin/bash -c "cd /home/bin/; ./detection ../testVid.mp4"
echo -en '\n'
xhost -local:
echo "Reverting xhost settings..."
echo -en '\n'
echo "Thanks for using our program!"

#TODO: Wenn man das Programm in Docker mit Strg+C beendet, wird der shell code danach nicht mehr ausgeführt
