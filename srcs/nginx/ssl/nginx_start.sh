#!/bin/bash

if [ ! -f /etc/ssl/certs/nginx.crt ]; then

echo "Nginx: setting up ssl ...";
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.cart -subj "/C=TR/ST=Istanbul/L=Istanbul/O=wordpress/CN=emakas.42.fr";

echo "Nginx: ssl is set up!";
fi

exec "$@"