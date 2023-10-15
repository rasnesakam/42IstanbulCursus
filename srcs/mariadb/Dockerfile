FROM debian:11

RUN apt-get update
RUN apt-get install mariadb-server mariadb-client -y


EXPOSE 3306
ENV WORDPRESS_DB_NAME="my_wordpress"
ENV WORDPRESS_DB_USER="my_wp_user"
ENV WORDPRESS_DB_PASSWORD="r00t123"

RUN service mariadb start  \
	&& echo "CREATE DATABASE IF NOT EXISTS ${WORDPRESS_DB_NAME}" | mariadb \
	&& echo "CREATE USER IF NOT EXISTS '${WORDPRESS_DB_USER}'@'%' IDENTIFIED BY '${WORDPRESS_DB_PASSWORD}';\
				GRANT ALL PRIVILEGES ON ${WORDPRESS_DB_NAME}.* to '${WORDPRESS_DB_USER}'@'%';\
				FLUSH PRIVILEGES;" | mariadb

CMD ["mysqld"]

