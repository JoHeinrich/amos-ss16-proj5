#/frameselector FULL_PATH_TO_HDF5_File.hdf5 BildIndex
#!/bin/bash
# Script for easier docker usage
set -e
echo -en '\n'
echo "Ubuntu Bash Start Script"
echo "This script will start our docker container. Please give the path to a HDF5 File, an optional frame index and the tag for the docker image you want to start."
echo -en '\n'
if [ ! -f $1 ] || [ $# -lt 2 ]; then 
  echo -en '\n'
  echo "Wrong Usage. Usage: ubuntuStreamDecoder.sh [ _FULL_PATH_TO_HDF5_FILE_ ] [ _CONTAINER_TAG_ ] [optional: _FRAME_INDEX_ ]"
  echo "Whitespaces in the path are not allowed!"
  echo "Example: script/ubuntuStreamDecoder.sh /home/file.hdf5 v1 10"  
  exit
fi  
echo "Configuring xhost"
xhost +local:
echo -en '\n'
echo "Starting the container now. All binaries can be found in /home/bin. The hdf5 file is mapped into the home directory."
#docker run -ti -v $1:/home/hdf5file.hdf5 -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -e LD_LIBRARY_PATH=/home/openCV/lib:$LD_LIBRARY_PATH amosproj5/amosbuildimage:$2 /bin/bash 
docker run -ti -v $1:/home/hdf5file.hdf5 -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -e LD_LIBRARY_PATH=/home/openCV/lib:$LD_LIBRARY_PATH amosproj5/amosbuildimage:$2 /bin/bash -c "cd /home/bin/; ./frameselector ../hdf5file.hdf5 $3"
echo -en '\n'
xhost -local:
echo "Reverting xhost settings..."
echo -en '\n'
echo "Thanks for using our program!"
