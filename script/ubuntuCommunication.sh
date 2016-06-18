#!/bin/bash
# Script for easier docker usage
set -e
echo -en '\n'
echo "Ubuntu Bash Start Script"
echo "This script will start our docker container for the communication demo. Please give the name of a docker network and the tag for the docker image you want to start the server."
echo -en '\n'

#gnome-terminal -e " \"worked\"" 

if [ $# -lt 2 ]; then 
  echo -en '\n'
  echo "Wrong Usage. Usage: ubuntuVideo.sh [ _NAME_OF_NETWORK_ ] [ _CONTAINER_TAG_ ]"
  echo "Whitespaces in the path are not allowed!"
  echo "Example: script/ubuntuVideo.sh testNW v1"  
  exit
fi 

# run server
gnome-terminal -e "./ubuntuCafServer.sh $1 $2"
sleep 1
./ubuntuCafClient.sh $1 $2

