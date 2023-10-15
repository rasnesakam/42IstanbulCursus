FROM debian:11

RUN apt-get update
RUN apt-get install -y php7.3 php-mysqli php-fpm wget sendmail

RUN \
	sed -i "s/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/" "/etc/php/7.3/fpm/pool.d/www.conf" &&\
	chown -R www-data:www-data /var/www/* &&\
	chown -R 755 /var/www/* &&\
	mkdir -p /run/php/ &&\
	touch /run/php/php7.3-fpm.pid;

EXPOSE 9000

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.daemon

RUN echo "Installing Wordpress CLI." &&\
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar &&\
	chmod +x wp-cli.phar &&\
	mv wp-cli.phar /usr/local/bin/wp

WORKDIR /var/www/html
RUN echo "Installing Wordpress." && \
	wp core download --allow-root && \
	wp core install --allow-root \
		--url=${WORDPRESS_URL} \
		--title=${WORDPRESS_TITLE} \
		--admin_user=${WORDPRESS_USER}\
		--admin_password=${WORDPRESS_PASSWORD}\
		--admin_email=${WORDPRESS_EMAIL}&& \
	wp user create --allow-root \
		${WORDPRESS_USER} ${WORDPRESS_EMAIL}\
		--user_pass=${WORDPRESS_PASSWORD};

RUN echo "Setting up Wordpress configuration." && \
	wp config create \
		--dbhost=${WORDPRESS_DB_HOST} \
		--dbname=${WORDPRESS_DB_NAME} \
		--dbuser=${WORDPRESS_DB_USER} \
		--dbpass=${WORDPRESS_DB_PASSWORD}

CMD ["/usr/sbin/php-fpm7.3", "--nodaemonize"]