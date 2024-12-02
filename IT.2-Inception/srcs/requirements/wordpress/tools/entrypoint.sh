#!/bin/bash

# start the mariadb service
SECONDS=0
while ! mysqladmin ping -h mariadb --silent; do
	echo "Waiting for MariaDB to start... ${SECONDS} seconds elapsed"
	sleep 1
done

echo "Database Name: $DB_NAME"
echo "Admin Name: $ADMIN_NAME"
echo "Admin Password: $ADMIN_PWD"
echo "WordPress URL: $WP_URL"
echo "WordPress Title: $WP_TITLE"
echo "Admin Email: $ADMIN_EMAIL"
echo "User Name: $USER_NAME"
echo "User Password: $USER_PWD"

# create a new wordpress configuration file
/wp-cli.phar config create	--allow-root \
							--dbname="$DB_NAME" \
							--dbuser="$ADMIN_NAME" \
							--dbpass="$ADMIN_PWD" \
							--dbhost=mariadb:3306 \
							--path='/var/www/wordpress'

# install wordpress
/wp-cli.phar core install --allow-root \
                          --url="$WP_URL" \
                          --title="$WP_TITLE" \
                          --admin_user="$ADMIN_NAME" \
                          --admin_password="$ADMIN_PWD" \
                          --admin_email="$ADMIN_EMAIL" \
                          --path='/var/www/wordpress'

# create a new wordpress user
/wp-cli.phar user create	--allow-root \
							"$USER_NAME" \
							"$USER_NAME@example.com" \
							--user_pass="$USER_PWD" \
							--role=author \
							--path='/var/www/wordpress'



# start the php-fpm service
mkdir -p /run/php
exec /usr/sbin/php-fpm7.4 -F
