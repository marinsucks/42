FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y \
	php \
	php-fpm \
	php-mysql \
	mariadb-client \
	wget \
	nano
RUN apt clean

RUN wget https://wordpress.org/latest.tar.gz; \
	mkdir -p /var/www; \
	tar -xzf latest.tar.gz -C /var/www; \
	rm latest.tar.gz; \
	chown -R root:root /var/www/wordpress


RUN sed -i 's/^.*clear_env.*$/clear_env = no/' /etc/php/7.4/fpm/pool.d/www.conf; \
	sed -i 's/^.*listen =.*$/listen = wordpress:9000/' /etc/php/7.4/fpm/pool.d/www.conf

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar; \
	chmod +x wp-cli.phar; \
	mv wp-cli.phar /usr/local/bin/wp

COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN	chmod +x /usr/local/bin/entrypoint.sh

#for debug
CMD [ "tail", "-f", "/usr/local/bin/entrypoint.sh" ] 
#ENTRYPOINT [ "entrypoint.sh" ]