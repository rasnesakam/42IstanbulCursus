FROM debian:11

RUN apt-get update
RUN apt-get install mariadb-server -y

COPY  ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./sql/initial_db.sql /var/www/

EXPOSE 3306

RUN rm -rf /run/mysqld/mysqld.sock && mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld
#RUN service mysql start && mysql < /var/www/initial_db.sql && rm -f var/www/

CMD ["mysqld_safe", "--user=mysql", "--skip-networking", "--socket=/var/run/mysqld/mysqld.sock", "--datadir=/var/lib/mysql"]
