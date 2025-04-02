#!/bin/sh

# Create ftp user
useradd -m -s /bin/bash "$FTP_USER_NAME"
echo "$FTP_USER_NAME:$FTP_USER_PWD" | chpasswd

# Create wordpress linked directory
mkdir -p /ftp/wordpress
chown $FTP_USER_NAME:$FTP_USER_NAME /ftp/wordpress
chmod a-w /ftp/wordpress

# avoid vsftpd error
mkdir -p /var/run/vsftpd/empty
chmod 755 /var/run/vsftpd/empty

exec vsftpd /etc/vsftpd.conf