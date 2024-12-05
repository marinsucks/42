FROM debian:bullseye

RUN apt-get update && apt-get install -y \
	php \
	php-fpm \
	php-mysql \
	wget \
	&& apt-get clean

RUN mkdir -p /var/www/adminer && \
	wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php -O /var/www/adminer/index.php

RUN sed -i 's/^.*listen =.*$/listen = 0.0.0.0:9001/' /etc/php/7.4/fpm/pool.d/www.conf && \
	sed -i 's/^.*clear_env.*$/clear_env = no/' /etc/php/7.4/fpm/pool.d/www.conf

EXPOSE 9001

RUN mkdir /run/php/
CMD ["php-fpm7.4", "-F"]
