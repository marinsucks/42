echo "CREATE DATABASE IF NOT EXISTS wordpress;" >>/etc/mysql/init.sql
echo "CREATE USER IF NOT EXISTS 'FrankBreak'@'localhost' IDENTIFIED BY 'ineedabreak';" >>/etc/mysql/init.sql
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'FrankBreak'@'localhost' WITH GRANT OPTION;" >>/etc/mysql/init.sql
echo "CREATE USER IF NOT EXISTS 'XavierNiel'@'localhost' IDENTIFIED BY '42_4ever_<3';" >>/etc/mysql/init.sql
echo "GRANT SELECT, INSERT, UPDATE, DELETE ON wordpress.* TO 'XavierNiel'@'localhost';" >>/etc/mysql/init.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY 'chillguy';" >>/etc/mysql/init.sql
echo "FLUSH PRIVILEGES;" >>/etc/mysql/init.sql

exec mysqld_safe