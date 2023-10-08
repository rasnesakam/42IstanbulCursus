FROM debian:12

RUN apt-get update
RUN apt-get install mariadb-server -y

COPY  .conf/50-server.cnf /etc/mysql/mariadb.conf.d/

# CMD ["mysqld"]