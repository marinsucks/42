FROM debian:bullseye

# Install dependencies
RUN apt-get update 
RUN apt-get install -y \
	nginx \
	openssl \
	&& apt-get clean

# Get SSL certificate
RUN mkdir -p /etc/nginx/ssl && \
	openssl req \
		-x509 \
		-nodes \
		-out /etc/nginx/ssl/inception.crt \
		-keyout /etc/nginx/ssl/inception.key \
		-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=${DOMAIN}/UID=${LOGIN}"

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY conf/static.html /var/www/static/index.html

ENTRYPOINT [ "nginx", "-g", "daemon off;" ]