# get baseimage
FROM ubuntu:latest

EXPOSE 18080

RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get -y install tzdata

RUN apt-get update \
  && apt-get install -y ssh \
      build-essential \
      gcc \
      g++ \
      git \
      gdb \
      clang \
      make \
      ninja-build \
      cmake \
      autoconf \
      automake \
      locales-all \
      dos2unix \
      rsync \
      tar \
      libboost-all-dev \
  && apt-get clean

RUN git clone https://github.com/redis/hiredis.git
RUN cd hiredis
RUN make
RUN make install

RUN git clone https://github.com/sewenew/redis-plus-plus.git
RUN cd redis-plus-plus
RUN mkdir build
RUN cd build
RUN cmake ..
RUN make
RUN make install
RUN cd ..