FROM ubuntu:14.04
MAINTAINER Daniel Goetz <daniel.dg.goetz@fau.de>
RUN apt-get update && apt-get install -y \ 
 libprotobuf8 \
 libhdf5-serial-dev \
 libhdf5-dev \
 hdf5-tools
ADD assets/AutoDrive /home/AutoDrive
