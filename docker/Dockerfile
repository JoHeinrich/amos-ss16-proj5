FROM osrgroup/amos-service-base-image:1.0
MAINTAINER Daniel Goetz <daniel.dg.goetz@fau.de>

# -------------------------------------- Install packages

# Install nginx and patch
COPY assets /assets
RUN echo "deb http://nginx.org/packages/mainline/ubuntu/ trusty nginx" > /etc/apt/sources.list.d/nginx.list \
  && apt-key add /assets/nginx_signing.key \
  && apt-get -y update \
  && apt-get -y --no-install-recommends install nginx patch \
  && scrub_image
RUN echo "Installing dependencies"  
RUN apt-get update && apt-get install -y \ 
 libhdf5-serial-dev \
 libhdf5-dev \
 hdf5-tools \
 g++ \
 make
RUN apt-get -y install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev 
RUN echo "Installing protobuf9"
RUN wget https://github.com/google/protobuf/releases/download/v2.6.1/protobuf-2.6.1.tar.gz \
  && tar xzf protobuf-2.6.1.tar.gz \
  && cd protobuf-2.6.1 \
  && ./configure \
  && make \
  && make check \
  && sudo make install \ 
  && sudo ldconfig

ENV HTML_INDEX_FILE AutoDrive
ADD assets/$HTML_INDEX_FILE /var/www/html/$HTML_INDEX_FILE
ADD assets/bin /home
ADD assets/openCV /home/openCV
#RUN export LD_LIBRARY_PATH=/home/openCV/lib/:$LD_LIBRARY_PATH
#RUN sudo ln /dev/null /dev/raw1394 
#sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
#sudo apt-get install libdc1394-22-dev
# export LD_LIBRARY_PATH=/home/openCV/lib/:$LD_LIBRARY_PATH
# sudo ln /dev/null /dev/raw1394
RUN bash /assets/finish_docker_build
