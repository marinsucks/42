#!/bin/bash

# start the mariadb service
SECONDS=0
while ! mysqladmin ping -h mariadb --silent; do
	echo "Waiting for MariaDB to start... ${SECONDS} seconds elapsed"
	sleep 1
done

# create a new wordpress configuration file
/wp-cli.phar config create	--allow-root \
							--dbname="$DB_NAME" \
							--dbuser="$ADMIN_NAME" \
							--dbpass="$ADMIN_PWD" \
							--dbhost=mariadb \
							--path=/var/www/wordpress

## install wordpress
#/wp-cli.phar core install --allow-root \
#                          --url=https://mbecker.42.fr/ \
#                          --title=Inception \
#                          --admin_user=admin \
#                          --admin_password=admin \
#                          --admin_email=admin@42.fr \
#                          --path=/var/www/wordpress

# install wordpress
/wp-cli.phar core install --allow-root \
                          --url=https://$DOMAIN/ \
                          --title=$WP_TITLE \
                          --admin_user=$ADMIN_NAME \
                          --admin_password=$ADMIN_PWD \
                          --admin_email=$ADMIN_EMAIL \
                          --path=/var/www/wordpress

# create a new user
/wp-cli.phar user create	--allow-root \
							"$USER_NAME" \
							"$USER_NAME@example.com" \
							--user_pass="$USER_PWD" \
							--role=author \
							--path=/var/www/wordpress



# start the php-fpm service
mkdir -p /run/php
exec /usr/sbin/php-fpm7.4 -F
