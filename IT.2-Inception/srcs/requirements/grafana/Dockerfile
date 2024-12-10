FROM debian:bullseye

RUN apt-get update && apt-get install -y wget tar && apt-get clean

RUN wget https://dl.grafana.com/oss/release/grafana-10.1.2.linux-amd64.tar.gz \
    && tar -zxvf grafana-10.1.2.linux-amd64.tar.gz \
    && mv grafana-10.1.2 /grafana \
    && rm grafana-10.1.2.linux-amd64.tar.gz

EXPOSE 3000

WORKDIR /grafana

CMD ["./bin/grafana-server", "--homepath=/grafana"]
