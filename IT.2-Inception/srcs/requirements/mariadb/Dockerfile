FROM debian:bullseye

RUN	apt-get update 
RUN apt-get install -y \
	mariadb-server \
	nano
RUN apt clean

EXPOSE 3306

COPY conf/mariadb.cnf /etc/mysql/mariadb.cnf

COPY ../tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN	chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT [ "entrypoint.sh" ]
