#
# helper.sh
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

#!/bin/bash
# This script is used by the amos-ss16-proj5.sh and amos-ss16-proj5-gui.sh to start our program in server mode inside the docker container
# Parameter 1 is docker network name, parameter 2 is container tag, parameter 3 is server port
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
docker run -ti --name=serverContainer --net=$1 -e LD_LIBRARY_PATH=/home/openCV/lib:$LD_LIBRARY_PATH amosproj5/amosbuildimage:$2 /bin/bash -c "ln -s /dev/null /dev/raw1394; /home/bin/amos-ss16-proj5 $3"
read -p "Press any key to exit > " -n1 junk
echo 
#docker run -ti -d --name=serverContainer --net=$1 amosproj5/amosbuildimage:$2
#docker exec -it serverContainer /bin/bash 
