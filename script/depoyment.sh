#!/bin/bash
# Script for easier docker usage 
set -e 
echo "Pulling docker image" 
docker pull amosproj5/amosbuildimage:v1 
echo "Finding image id" 
line=$(docker images amosproj5/amosbuildimage:v1) 
echo "line" 
echo -e '\n' 
echo "$line" 
ip=$(echo $line | cut -c66-77) 
echo "$ip" 
echo "Tagging the image" 
docker tag $ip amosproj5/amosbuildimage:release 
echo "Logging in to docker" 
docker login --username=amosproj5 --email=daniel.dg.goetz@fau.de 
# (enter password afterwards, which is in slack) 
docker push amosproj5/amosbuildimage:release