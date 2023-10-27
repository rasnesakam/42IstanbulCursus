#!/bin/bash

cd /var/www/html;

if [ ! -f wp-config.php ]
 	then
		echo "Downloading Wordpress.";
		wp core download --allow-root

		echo "Setting up Wordpress configuration.";
		wp config create --allow-root \
			--dbhost=${WORDPRESS_DB_HOST} \
			--dbname=${WORDPRESS_DB_NAME} \
			--dbuser=${WORDPRESS_DB_USER} \
			--dbpass=${WORDPRESS_DB_PASSWORD} && \
		echo "Installing Wordpress.";
		wp core install --allow-root \
			--url=${WORDPRESS_URL} \
			--title=${WORDPRESS_TITLE} \
			--admin_user=${WORDPRESS_ADMIN_LOGIN}\
			--admin_password=${WORDPRESS_ADMIN_PASSWORD}\
			--admin_email=${WORDPRESS_ADMIN_EMAIL}&& \
		wp user create --allow-root \
			${WORDPRESS_ADMIN_LOGIN} ${WORDPRESS_ADMIN_EMAIL}\
			--user_pass=${WORDPRESS_PASSWORD};

fi

echo "Executing arguments: $@";
exec "$@"