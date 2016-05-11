FROM osrgroup/amos-downloader-base-image:1.0
MAINTAINER Daniel Goetz <daniel.dg.goetz@fau.de>
RUN apt-get update && apt-get install -y \ 
 libprotobuf8 \
 libhdf5-serial-dev \
 libhdf5-dev \
 hdf5-tools
ENV HTML_INDEX_FILE ProtobufDecoder
ADD assets/ProtobufDecoder /home/ProtobufDecoder
ADD assets/$HTML_INDEX_FILE /var/www/html/$HTML_INDEX_FILE
