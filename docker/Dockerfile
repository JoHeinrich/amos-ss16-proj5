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
RUN apt-get update && apt-get install -y \ 
 libprotobuf8 \
 libhdf5-serial-dev \
 libhdf5-dev \
 hdf5-tools
ADD assets/AutoDrive /home/AutoDrive

ENV HTML_INDEX_FILE AutoDrive
ADD assets/$HTML_INDEX_FILE /var/www/html/$HTML_INDEX_FILE
ADD ../build/bin /home/bin
RUN bash /assets/finish_docker_build
