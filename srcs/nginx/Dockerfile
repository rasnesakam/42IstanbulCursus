#FROM nginx
#RUN rm /etc/nginx/nginx.conf /etc/nginx/conf.d/default.conf

# COPY content /usr/share/nginx/html
#COPY conf /etc/nginx
#burası senin yaptığın kısımdı şimdi benimkine geçiyorum

FROM debian:11

RUN apt-get update
RUN apt-get install -y nginx openssl

#COPY ./conf/nginx.conf /etc/nginx/sites-enable/default
COPY ./ssl/nginx_start.sh /var/www

EXPOSE 443

RUN chmod +x /var/www/nginx_start.sh

RUN "/var/www/nginx_start.sh"

ENTRYPOINT [ "nginx" ]

CMD [ "-g", "daemon off;"]