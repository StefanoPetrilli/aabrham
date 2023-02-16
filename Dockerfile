FROM ubuntu:jammy-20230126
LABEL Description="Aabrham"

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
      libasio-dev \
  && apt-get clean

RUN git clone https://github.com/sewenew/redis-plus-plus.git
WORKDIR redis-plus-plus
RUN mkdir build
WORKDIR build
RUN cmake ..
RUN make
RUN make install

WORKDIR ..

RUN git clone https://github.com/CrowCpp/Crow.git
WORKDIR Crow
RUN mkdir build
WORKDIR build
RUN cmake .. -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF
RUN make install

WORKDIR ../../aanrham

COPY src/ src/
COPY test/ test/
COPY CMakeLists.txt .
RUN cmake -B build -DCMAKE_BUILD_TYPE=release
RUN cmake --build build --config release

COPY docker_entrypoint.sh .
ENTRYPOINT ["./docker_entrypoint.sh"]