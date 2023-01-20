#! /bin/sh
docker build -t aabrham-container:0.1 -f Dockerfile .
docker run -p 127.0.0.1:18080:18080 --name aabrham aabrham-container:0.1
