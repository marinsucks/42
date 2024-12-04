FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y \
	php \
	php-fpm \
	php-mysql \
	mariadb-client \
	wget
RUN apt clean

EXPOSE 9000

# Configure php-fpm
RUN sed -i 's/^.*clear_env.*$/clear_env = no/' /etc/php/7.4/fpm/pool.d/www.conf && \
	sed -i 's/^.*listen =.*$/listen = 0.0.0.0:9000/' /etc/php/7.4/fpm/pool.d/www.conf

# Install wordpress
RUN wget https://wordpress.org/latest.tar.gz && \
	mkdir -p /var/www && \
	tar -xzf latest.tar.gz -C /var/www && \
	rm latest.tar.gz && \
	chmod -R 755 /var/www/wordpress && \
	chown -R root:root /var/www/wordpress

# Configure wordpress
WORKDIR /var/www/wordpress
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \ 
	mv wp-cli.phar /usr/local/bin/wp


COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN	chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT [ "entrypoint.sh" ]
#ENTRYPOINT [ "tail", "-f", "/dev/null" ]