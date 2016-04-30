FROM ubuntu:16.04
MAINTAINER Daniel Goetz <daniel.dg.goetz@fau.de>
RUN apt-get update && apt-get install -y \ 
 libprotobuf9v5 \
 libhdf5-cpp-11 \
 hdf5-tools
ADD assets/AutoDrive /home/AutoDrive
