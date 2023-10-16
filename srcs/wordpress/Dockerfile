FROM debian:12

RUN apt-get update
RUN apt-get install -y php php-mysqli php-fpm wget sendmail

EXPOSE 9000

ENV WORDPRESS_URL=${WORDPRESS_URL}
ENV WORDPRESS_TITLE=${WORDPRESS_TITLE}

ENV WORDPRESS_ADMIN_LOGIN=${WORDPRESS_ADMIN_LOGIN}
ENV WORDPRESS_ADMIN_PASSWORD=${WORDPRESS_ADMIN_PASSWORD}
ENV WORDPRESS_ADMIN_PASSWORD=${WORDPRESS_ADMIN_PASSWORD}
ENV WORDPRESS_ADMIN_EMAIL=${WORDPRESS_ADMIN_EMAIL}

ENV WORDPRESS_USER_LOGIN=${WORDPRESS_USER_LOGIN}
ENV WORDPRESS_USER_PASSWORD=${WORDPRESS_USER_PASSWORD}
ENV WORDPRESS_USER_EMAIL=${WORDPRESS_USER_EMAIL}

ENV WORDPRESS_DB_NAME=${WORDPRESS_DB_NAME}
ENV WORDPRESS_DB_HOST=${WORDPRESS_DB_HOST}
ENV WORDPRESS_DB_USER=${WORDPRESS_DB_USER}
ENV WORDPRESS_DB_PASSWORD=${WORDPRESS_DB_PASSWORD}


RUN PHP_VERSION=$(php -r 'echo PHP_MAJOR_VERSION . "." . PHP_MINOR_VERSION;') && \
    echo "PHP_VERSION=$PHP_VERSION" >> /etc/environment

RUN sed -i "s/listen = \/run\/php\/php$(php -r 'echo PHP_MAJOR_VERSION . "." . PHP_MINOR_VERSION;')-fpm.sock/listen = 9000/" "/etc/php/$(php -r 'echo PHP_MAJOR_VERSION . "." . PHP_MINOR_VERSION;')/fpm/pool.d/www.conf" && \
	chown -R www-data:www-data /var/www/* && \
	chown -R 755 /var/www/* && \
	mkdir -p /run/php && \
	touch /run/php/php$(php -r 'echo PHP_MAJOR_VERSION . "." . PHP_MINOR_VERSION;')-fpm.pid

RUN echo "Installing Wordpress CLI." &&\
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar &&\
	chmod +x wp-cli.phar &&\
	mv wp-cli.phar /usr/local/bin/wp

WORKDIR /var/www/html

RUN echo "Downloading Wordpress." && \
	wp core download --allow-root

RUN echo "Setting up Wordpress configuration." && \
	apt-get install -y mariadb-client && \
	wp config create --allow-root \
		--dbhost=${WORDPRESS_DB_HOST} \
		--dbname=${WORDPRESS_DB_NAME} \
		--dbuser=${WORDPRESS_DB_USER} \
		--dbpass=${WORDPRESS_DB_PASSWORD} && \
	apt-get remove mariadb-client

RUN echo "Installing Wordpress." && \
	wp core install --allow-root \
		--url=${WORDPRESS_URL} \
		--title=${WORDPRESS_TITLE} \
		--admin_user=${WORDPRESS_USER}\
		--admin_password=${WORDPRESS_PASSWORD}\
		--admin_email=${WORDPRESS_EMAIL}&& \
	wp user create --allow-root \
		${WORDPRESS_USER} ${WORDPRESS_EMAIL}\
		--user_pass=${WORDPRESS_PASSWORD};


CMD ["/usr/sbin/php-fpm$(php -r 'echo PHP_MAJOR_VERSION . "." . PHP_MINOR_VERSION;')", "--nodaemonize"]