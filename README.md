# Inception
Inception is the project of 42 for teach to use docker and docker compose.
## Usage
To run this application, you need to have `docker` and `docker-compose-plugin` installed.

If you have the packages that mentioned above, simply run:
```
docker compose up -d
```

## Deep Dive
Our project consists of three [containers](https://www.docker.com/resources/what-container/).

* mariadb
* nginx
* wordpress

### Mariadb
Mariadb is a relational database that used in our project. It is responsible for holding various datas for our application. There are no more details to mention about this. But in case you want to deep dive, [check out this link](https://mariadb.org/)

### Nginx
Nginx is a another service that we use in our project. It is a reverse-proxy server. It is responsible for routing requests according to the configuration file ([inception.conf](./srcs/requirements/nginx/conf/inception.conf))

### Wordpress
Wordpress is the last service that we use in our project. This service is actually holds our website. Wordpress is open-source blog site. You can freely install it and begin to serve your blog site.

---
Our services are dependent on each other. To solve this problem, we are declaring that our services dependent on some services to start. We simply can do it like this:

```yml
// docker-compose.yml

services:
  wordpress:
    build: ./requirements/wordpress
    container_name: my_wordpress
    depends_on:
      - mariadb
//	...
```

[Wordpress](#wordpress) is dependent on mariadb to start. Because wordpress needs to store it's configuration and other datas through [mariadb](#mariadb).
And also [nginx](#nginx) is dependent on [wordpress](#wordpress) to start. Because in configuration file, [nginx](#nginx) uses the address of [wordpress](#wordpress) to connect.
