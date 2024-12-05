#!/bin/bash

# wait for the mariadb service to be running
SECONDS=0
while ! mysqladmin ping -h mariadb --silent; do
	echo "Waiting for MariaDB to start... ${SECONDS} seconds elapsed"
	sleep 1
done

# create a new wordpress configuration file
wp config create	--allow-root \
					--dbname="$DB_NAME" \
					--dbuser="$ADMIN_NAME" \
					--dbpass="$ADMIN_PWD" \
					--dbhost=mariadb \
					--path=/var/www/wordpress

# install wordpress
wp core install --allow-root \
				--url=https://$DOMAIN/ \
				--title=$WP_TITLE \
				--admin_user=$ADMIN_NAME \
				--admin_password=$ADMIN_PWD \
				--admin_email=$ADMIN_EMAIL \
				--path=/var/www/wordpress

# create a new user
wp user create	--allow-root \
				"$USER_NAME" \
				"$USER_NAME@example.com" \
				--user_pass="$USER_PWD" \
				--role=author \
				--path=/var/www/wordpress

# install and enable the redis cache plugin
sed -i "/\/\* That's all, stop editing! Happy publishing. \*\//i define('WP_REDIS_HOST', 'redis');\ndefine('WP_REDIS_PORT', 6379);" /var/www/wordpress/wp-config.php
wp plugin install redis-cache --activate --allow-root --path=/var/www/wordpress
wp redis enable --allow-root --path=/var/www/wordpress

# start the php-fpm service
mkdir -p /run/php
exec /usr/sbin/php-fpm7.4 -F
