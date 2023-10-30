FROM debian:12

RUN apt-get update
RUN apt-get install -y php php-mysqli php-fpm wget sendmail  mariadb-client

EXPOSE 9000

RUN sed -i "s/listen = \/run\/php\/php$(php -r 'echo PHP_MAJOR_VERSION . "." . PHP_MINOR_VERSION;')-fpm.sock/listen = 9000/" "/etc/php/$(php -r 'echo PHP_MAJOR_VERSION . "." . PHP_MINOR_VERSION;')/fpm/pool.d/www.conf" && \
	chown -R www-data:www-data /var/www/* && \
	chown -R 755 /var/www/* && \
	mkdir -p /run/php && \
	touch /run/php/php$(php -r 'echo PHP_MAJOR_VERSION . "." . PHP_MINOR_VERSION;')-fpm.pid

RUN echo "Installing Wordpress CLI." &&\
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar &&\
	chmod +x wp-cli.phar &&\
	mv wp-cli.phar /usr/local/bin/wp


COPY ./sh/index.sh /usr/local/bin/start_container
RUN chmod a+x /usr/local/bin/start_container

ENTRYPOINT ["start_container"]

CMD ["php-fpm8.2", "--nodaemonize"]