FROM debian:bullseye

# Install dependencies
RUN apt-get update 
RUN apt-get install -y nginx openssl

# Get SSL certificate
RUN mkdir -p /etc/nginx/ssl && \
		openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=login.42.fr/UID=login"
		#! make sure to change login

COPY conf/nginx.conf /etc/nginx/nginx.conf

RUN chmod -R 755 /var/www/html

RUN mv /var/www/html/index.nginx-debian.html /var/www/html/index.html

CMD [ "nginx", "-g", "daemon off;" ]