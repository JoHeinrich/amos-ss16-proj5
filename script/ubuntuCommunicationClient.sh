#!/bin/bash
# Script for easier docker usage
set -e
echo -en '\n'
echo "Ubuntu Bash Start Script"
echo "This script will start our docker container for the communication demo. Please give the name of a docker network and the tag for the docker image you want to start the client."
echo -en '\n'
if [ $# -lt 2 ]; then 
  echo -en '\n'
  echo "Wrong Usage. Usage: ubuntuVideo.sh [ _NAME_OF_NETWORK_ ] [ _CONTAINER_TAG_ ]"
  echo "Whitespaces in the path are not allowed!"
  echo "Example: script/ubuntuVideo.sh testNW v1"  
  exit
fi 

# checking if client is running / exited
containerRunning=$(docker ps -a -f name=clientContainer)
flag=`echo $containerRunning|awk '{print match($0,"clientContainer")}'`;
echo $flag
if [ $flag -gt 0 ]; then
  docker stop clientContainer
  docker rm -fv clientContainer
fi
#docker run -ti --name=serverContainer --net=$1 amosproj5/amosbuildimage:$2 /bin/bash -c "/home/bin/server 8080"
#echo "test"
echo -en '\n'
echo "Take note of the server ip!"
docker network inspect $1
echo -en '\n'
echo "Starting the client"
docker run -ti -d --name=clientContainer --net=$1 amosproj5/amosbuildimage:$2
docker exec -it serverContainer /bin/bash 
