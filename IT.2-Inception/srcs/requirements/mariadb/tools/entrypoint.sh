#!/bin/bash

echo "CREATE DATABASE IF NOT EXISTS ${DB_NAME};" >>/etc/mysql/init.sql

echo "CREATE USER IF NOT EXISTS '${ADMIN_NAME}'@'%' IDENTIFIED BY '${ADMIN_PWD}';" >>/etc/mysql/init.sql
#echo "CREATE USER IF NOT EXISTS '${USER_NAME}'@'%' IDENTIFIED BY '${USER_PWD}';" >>/etc/mysql/init.sql

echo "GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${ADMIN_NAME}'@'%' WITH GRANT OPTION;" >>/etc/mysql/init.sql
#echo "GRANT SELECT, INSERT, UPDATE, DELETE ON ${DB_NAME}.* TO '${USER_NAME}'@'%';" >>/etc/mysql/init.sql

echo "ALTER USER 'root'@'%' IDENTIFIED BY '${DB_ROOT_PWD}';" >>/etc/mysql/init.sql

echo "FLUSH PRIVILEGES;" >>/etc/mysql/init.sql

exec mysqld_safe

#mysql -u example_admin -pexample_admin wordpress
#SELECT User FROM mysql.user;
