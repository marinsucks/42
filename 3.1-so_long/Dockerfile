FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install -y build-essential libx11-dev libxext-dev git libbsd-dev

COPY . /so_long

WORKDIR /so_long

RUN make VERBOSE=1

CMD ["./so_long"]
