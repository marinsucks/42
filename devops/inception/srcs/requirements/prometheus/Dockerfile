FROM debian:bullseye

RUN apt-get update && apt-get install -y wget && apt-get clean

RUN wget https://github.com/prometheus/prometheus/releases/download/v2.48.1/prometheus-2.48.1.linux-amd64.tar.gz \
	&& tar xzf prometheus-2.48.1.linux-amd64.tar.gz \
	&& mv prometheus-2.48.1.linux-amd64 /prometheus \
	&& rm prometheus-2.48.1.linux-amd64.tar.gz

EXPOSE 9090

COPY config/prometheus.yml /prometheus/prometheus.yml

CMD ["/prometheus/prometheus", "--config.file=/prometheus/prometheus.yml"]
