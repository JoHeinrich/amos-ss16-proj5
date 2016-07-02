#!/bin/bash
# Script for easier docker usage
# Parameter 1 is docker network name, parameter 2 is container tag
set -e
echo -en '\n'
# Checking if server is running / exited
containerRunning=$(docker ps -a -f name=serverContainer)
flag=`echo $containerRunning|awk '{print match($0,"serverContainer")}'`;
#echo $flag
if [ $flag -gt 0 ]; then
  docker stop serverContainer
  docker rm -fv serverContainer
fi
echo "Starting the server on port $3"
echo -en '\n'
docker run -ti --name=serverContainer --net=$1 -e LD_LIBRARY_PATH=/home/openCV/lib:$LD_LIBRARY_PATH amosproj5/amosbuildimage:$2 /bin/bash -c "/home/bin/amos-ss16-proj5 $3"
read -p "Press any key to exit > " -n1 junk
echo 
#docker run -ti -d --name=serverContainer --net=$1 amosproj5/amosbuildimage:$2
#docker exec -it serverContainer /bin/bash 
