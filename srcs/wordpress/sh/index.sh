#!/bin/bash

cd /var/www/html;

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
	--admin_user=${WORDPRESS_USER}\
	--admin_password=${WORDPRESS_PASSWORD}\
	--admin_email=${WORDPRESS_EMAIL}&& \
wp user create --allow-root \
	${WORDPRESS_USER} ${WORDPRESS_EMAIL}\
	--user_pass=${WORDPRESS_PASSWORD};

echo "Executing arguments: $@";
exec "$@"