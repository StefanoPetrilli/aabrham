# get baseimage
FROM ubuntu:latest

EXPOSE 18080

RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get -y install tzdata

RUN apt-get update \
  && apt-get install -y \
      ssh \
      build-essential \
      gcc \
      g++ \
      git \
      gdb \
      make \
      cmake \
      tar \
      libboost-all-dev \
      libhiredis-dev \
  && apt-get clean

RUN git clone https://github.com/sewenew/redis-plus-plus.git
WORKDIR redis-plus-plus
RUN mkdir build
WORKDIR build
RUN cmake ..
RUN make
RUN make install