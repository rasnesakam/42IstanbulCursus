FROM debian:12

RUN apt-get update
RUN apt-get install -y mariadb-server

EXPOSE 3306

ARG DB_NAME
ARG DB_USER
ARG DB_PASSWORD
ARG ROOT_PASSWORD

COPY ./sh/init_root.sh /usr/local/bin/init_root
RUN chmod +x /usr/local/bin/init_root

COPY ./sh/init_db.sh /usr/local/bin/init_db
RUN chmod +x /usr/local/bin/init_db

RUN service mariadb start && init_db
RUN service mariadb start && init_root

RUN sed -i "s/bind-address/#bind-address/" "/etc/mysql/mariadb.conf.d/50-server.cnf"  

ENTRYPOINT ["mariadbd"]

CMD ["-u", "root"]

