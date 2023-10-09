FROM debian:11
RUN apt-get update
RUN apt-get -y install php7.3 php-mysqli php-fpm wget sendmail

EXPOSE 9000


COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d
COPY ./tools /var/www/




WORKDIR /usr/src/wordpress
RUN set -eux; \
	find /etc/apache2 -name '*.conf' -type f -exec sed -ri -e "s!/var/www/html!$PWD!g" -e "s!Directory /var/www/!Directory $PWD!g" '{}' +; \
	cp -s wp-config-docker.php wp-config.php
COPY custom-theme/ ./wp-content/themes/custom-theme/
COPY custom-plugin/ ./wp-content/plugins/custom-plugin/

ENV WORDPRESS_DB_HOST="inception"
ENV WORDPRESS_DB_USER="emakas"
ENV WORDPRESS_DB_PASSWORD="1234"
ENV WORDPRESS_DB_NAME="db_inception"
