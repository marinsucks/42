#create a new wordpress configuration file
wp config create	--allow-root \
					--dbname=$DB_NAME \
					--dbuser=$DB_ADMIN_UNAME \
					--dbpass=$DB_ADMIN_PWD \
					--dbhost=mariadb:3306 \
					--path='/var/www/wordpress'

# create a new wordpress user
wp user create	--allow-root \
				XavierNiel \
				XavierNiel@example.com \
				--user_pass='42_4ever_<3' \
				--role=author \
				--path='/var/www/wordpress'