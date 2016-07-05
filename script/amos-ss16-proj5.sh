#
# amos-ss16-proj5.sh
# Projectname: amos-ss16-proj5
#
# Created on 28.05.2016.
# Copyright (c) 2016 de.fau.cs.osr.amos2016.gruppe5
#
# This file is part of the AMOS Project 2016 @ FAU
# (Friedrich-Alexander University Erlangen-Nürnberg)
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public
# License along with this program. If not, see
# <http://www.gnu.org/licenses/>.
#

#amos-ss16-proj5.sh [ _CONTAINER_TAG_ ] [ _FULL_PATH_TO_FILE_ ] [ _NAME_OF_NETWORK_ ] [ _PORT_ ]
#!/bin/bash
# Script for easier docker usage
set -e
echo -en '\n'
echo "AMOS Group 5 Start Script"
echo "This script will start our docker container for you. Please give a port number, the tag for the docker image you want to start, an optional server ip address, and an optional full path to a HDF5 or MP4 file."
echo -en '\n'
if [ $# -lt 4 ]; then 
	echo -en '\n'
	echo "Wrong Usage. Usage: amos-ss16-proj5.sh [ _CONTAINER_TAG_ ] [ _FULL_PATH_TO_FILE_ ] [ _NAME_OF_NETWORK_ ] [ _PORT_ ]"
	echo "Whitespaces in the path are not allowed!"
	echo "Example: script/amos-ss16-proj5.sh release /home/file.hdf5 dockerNW 8080 (localhost)"  
	exit 1
fi 

# Checking if the given file is valid
if [ ! -f "$2" ]; then
	echo "Invalid Filepath"
	echo -en '\n'
	exit 1
fi

# Get script directory 
dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Start the server -- needs the docker network, container tag, and the server port
gnome-terminal -e "$dir/helper.sh $3 $1 $4"
sleep 3




# HDF5 File given
if [ "${2##*.}" == "hdf5" ]; then
	# checking if client is running / exited
	containerRunning=$(docker ps -a -f name=clientContainer)
	flag=`echo $containerRunning|awk '{print match($0,"clientContainer")}'`;
	#echo $flag
	if [ $flag -gt 0 ]; then
	  docker stop clientContainer
	  docker rm -fv clientContainer
	fi
	
	# Getting server ip via docker network
	echo "Fetching server ip"
	echo -en '\n'
	line=$(docker network inspect $3 | sed -n '/serverContainer/{n;n;n;p}')
	ip=$(echo $line | cut -c17-26)
	
	# Configuring the xhost
	echo "Configuring xhost"
	xhost +local:
	
	# Starting the client inside the docker container
	echo "Starting the client"
	echo -en '\n'
	docker run -ti --name=clientContainer --net=$3 -v $2:/home/hdf5file.hdf5 -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -e LD_LIBRARY_PATH=/home/openCV/lib:$LD_LIBRARY_PATH amosproj5/amosbuildimage:$1 /bin/bash -c "ln -s /dev/null /dev/raw1394; cd /home/bin/; ./amos-ss16-proj5 $4 $ip ../hdf5file.hdf5"
	echo -en '\n'
	xhost -local:
	echo "Reverting xhost settings..."
	echo -en '\n'
	echo "Thanks for using our program!"
	exit 0
fi

# mp4 File given
if [ "${2##*.}" == "mp4" ]; then
  	# checking if client is running / exited
	containerRunning=$(docker ps -a -f name=clientContainer)
	flag=`echo $containerRunning|awk '{print match($0,"clientContainer")}'`;
	echo $flag
	if [ $flag -gt 0 ]; then
	  docker stop clientContainer
	  docker rm -fv clientContainer
	fi
	
	# Getting server ip via docker network
	echo "Fetching server ip"
	echo -en '\n'
	line=$(docker network inspect $3 | sed -n '/serverContainer/{n;n;n;p}')
	ip=$(echo $line | cut -c17-26)
	
	# Configuring the xhost
	echo "Configuring xhost"
	xhost +local:
	
	# Starting the client inside the docker container 
	echo "Starting the client"
	echo -en '\n'
	docker run -ti --name=clientContainer --net=$3 -v $2:/home/mp4file.mp4 -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -e LD_LIBRARY_PATH=/home/openCV/lib:$LD_LIBRARY_PATH amosproj5/amosbuildimage:$1 /bin/bash -c "ln -s /dev/null /dev/raw1394; cd /home/bin/; ./amos-ss16-proj5 $4 $ip ../mp4file.mp4"
	echo -en '\n'
	xhost -local:
	echo "Reverting xhost settings..."
	echo -en '\n'
	echo "Thanks for using our program!"
	exit 0
fi
