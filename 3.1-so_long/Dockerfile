FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install -y build-essential libx11-dev libxext-dev git libbsd-dev

# Clone minilibx-linux from GitHub
#RUN git clone https://github.com/42Paris/minilibx-linux.git

## Build minilibx-linux
#WORKDIR /minilibx-linux
#RUN make

COPY . /so_long

WORKDIR /so_long

RUN make VERBOSE=1

CMD ["./so_long"]
