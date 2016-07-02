#amos-ss16-proj5.sh [ _CONTAINER_TAG_ ] [ _FULL_PATH_TO_FILE_ ] [ _NAME_OF_NETWORK_ ] [ _PORT_ ]
#!/bin/bash
# Script for easier docker usage
set -e
echo -en '\n'
echo "Ubuntu Bash Start Script"
echo "This script will start our docker container. Please give a port number, the tag for the docker image you want to start, the name of a docker network, and pick either an mp4 or hdf5 file."

# Open Form for start parameters
OUTPUT=$(zenity --forms --title="Amos SS16 Proj5" --text="Enter program parameters" --separator="," --add-entry="Container Tag" --add-entry="Docker Network Name" --add-entry="Port")
accepted=$?
if ((accepted != 0)); then
    echo "something went wrong"
    exit 1
fi

# read parameters from form
tag=$(awk -F, '{print $1}' <<<$OUTPUT)
network=$(awk -F, '{print $2}' <<<$OUTPUT)
port=$(awk -F, '{print $3}' <<<$OUTPUT)

# check for blank fields
if [ "$tag" == "" ] || [ "$network" == "" ] || [ "$port" == "" ];then
	echo -en '\n'
	echo "No empty parameters allowed"
	echo -en '\n'
	exit 1
fi

# open file manager to pick mp4 or hdf5 files
FILE=`zenity --file-selection --title="Select either an mp4 or hdf5 File" --file-filter='*.mp4 *.hdf5 *.MP4 *.HDF5'`

# Checking if the given file is valid
if [ ! -f "$FILE" ]; then
	echo "Invalid Filepath"
	echo -en '\n'
	exit 1
fi

# Get script directory 
dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Start the server -- needs the docker network, container tag, and the server port
gnome-terminal -e "$dir/helper.sh $network $tag $port"
sleep 3



# HDF5 File given
if [ "${FILE##*.}" == "hdf5" ]; then
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
	line=$(docker network inspect $network | sed -n '/serverContainer/{n;n;n;p}')
	ip=$(echo $line | cut -c17-26)
	
	#echo "$ip"
	# Configuring the xhost
	echo "Configuring xhost"
	xhost +local:
	
	# Starting the client
	echo "Starting the client"
	echo -en '\n'
	docker run -ti --name=clientContainer --net=$network -v $FILE:/home/hdf5file.hdf5 -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -e LD_LIBRARY_PATH=/home/openCV/lib:$LD_LIBRARY_PATH amosproj5/amosbuildimage:$tag /bin/bash -c "ln -s /dev/null /dev/raw1394; cd /home/bin/; ./amos-ss16-proj5 $port $ip ../hdf5file.hdf5"
	echo -en '\n'
	xhost -local:
	echo "Reverting xhost settings..."
	echo -en '\n'
	echo "Thanks for using our program!"
	exit 0
fi

# mp4 File given
if [ "${FILE##*.}" == "mp4" ]; then
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
	line=$(docker network inspect $network | sed -n '/serverContainer/{n;n;n;p}')
	ip=$(echo $line | cut -c17-26)
#	echo $ip
	echo "Configuring xhost"
	xhost +local:
	echo "Starting the client"
	echo -en '\n'
#	echo "/home/bin/amos-ss16-proj5 $4 $ip ../mp4file.mp4"
	docker run -ti --name=clientContainer --net=$network -v $FILE:/home/mp4file.mp4 -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -e LD_LIBRARY_PATH=/home/openCV/lib:$LD_LIBRARY_PATH amosproj5/amosbuildimage:$tag /bin/bash -c "ln -s /dev/null /dev/raw1394; cd /home/bin/; ./amos-ss16-proj5 $port $ip ../mp4file.mp4"
	echo -en '\n'
	xhost -local:
	echo "Reverting xhost settings..."
	echo -en '\n'
	echo "Thanks for using our program!"
	exit 0
fi




