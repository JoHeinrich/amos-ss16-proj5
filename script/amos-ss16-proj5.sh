#./AutoDrive <port> (SERVER_IP_ADRESS FULL_PATH_TO_HDF5_FILE/MP4_FILE)
#!/bin/bash
# Script for easier docker usage
set -e
echo -en '\n'
echo "Ubuntu Bash Start Script"
echo "This script will start our docker container. Please give a port number, the tag for the docker image you want to start, an optional server ip address, and an optional full path to a HDF5 or MP4 file."
echo -en '\n'
if [ $# -lt 4 ]; then 
	echo -en '\n'
	echo "Wrong Usage. Usage: caotic.sh [ _CONTAINER_TAG_ ] [ _FULL_PATH_TO_FILE_ ] [ _NAME_OF_NETWORK_ ] [ _PORT_ ]"
	echo "Whitespaces in the path are not allowed!"
	echo "Example: script/caotic.sh release /home/file.hdf5 dockerNW 8080 (localhost)"  
	exit 1
fi 

# Checking if the given file is valid
if [ ! -f "$2" ]; then
	echo "Invalid Filepath"
	echo -en '\n'
	exit 1
fi

# Start the server -- needs the docker network and the server port
gnome-terminal -e "./helper.sh $3 $1"
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
	
	#echo "$ip"
	# Configuring the xhost
	echo "Configuring xhost"
	xhost +local:
	
	# Starting the client
	echo "Starting the client"
	echo -en '\n'
	docker run -ti --name=clientContainer --net=$3 -v $2:/home/hdf5file.hdf5 -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -e LD_LIBRARY_PATH=/home/openCV/lib:$LD_LIBRARY_PATH amosproj5/amosbuildimage:$1 /bin/bash -c "/home/bin/amos-ss16-proj5 $4 $ip ../hdf5file.hdf5"
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
	echo "Fetching server ip"
	echo -en '\n'
	line=$(docker network inspect $3 | sed -n '/serverContainer/{n;n;n;p}')
	ip=$(echo $line | cut -c17-26)
	#echo "$ip"
	echo "Configuring xhost"
	xhost +local:
	echo "Starting the client"
	echo -en '\n'
	docker run -ti --name=clientContainer --net=$3 -v $2:/home/mp4file.mp4 -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -e LD_LIBRARY_PATH=/home/openCV/lib:$LD_LIBRARY_PATH amosproj5/amosbuildimage:$1 /bin/bash -c "/home/bin/amos-ss16-proj5 $4 $ip ../mp4file.mp4"
	echo -en '\n'
	xhost -local:
	echo "Reverting xhost settings..."
	echo -en '\n'
	echo "Thanks for using our program!"
	exit 0
fi
