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
#echo $flag
if [ $flag -gt 0 ]; then
  docker stop clientContainer
  docker rm -fv clientContainer
fi
echo "Fetching server ip"
echo -en '\n'
line=$(docker network inspect testNW | sed -n '/serverContainer/{n;n;n;p}')
ip=$(echo $line | cut -c17-26)
#echo "$ip"
echo "Starting the client"
echo -en '\n'
docker run -ti --name=clientContainer --net=$1 amosproj5/amosbuildimage:$2 /bin/bash -c "/home/bin/client $ip 8080"
#docker run -ti -d --name=clientContainer --net=$1 amosproj5/amosbuildimage:$2
#docker exec -it clientContainer /bin/bash 
