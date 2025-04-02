FROM debian:bullseye

# Install vsftpd
RUN apt-get update && apt-get install -y \
    vsftpd \
    && apt-get clean

COPY conf/vsftpd.conf /etc/vsftpd.conf

EXPOSE 21

COPY tools/entrypoint.sh /usr/local/sbin/entrypoint.sh
RUN chmod +x /usr/local/sbin/entrypoint.sh
CMD ["entrypoint.sh"]
