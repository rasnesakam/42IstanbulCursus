DIR_DATA = $(HOME)/data
DIR_SRCS = srcs
DATA_MARIADB = ${DIR_DATA}/db
DATA_WORDPRESS = ${DIR_DATA}/wp
FILE_COMPOSE = ${DIR_SRCS}/docker-compose.yml
FILE_DOTENV = ${DIR_SRCS}/.env

VAL_VOLUME_DB = VOLUME_MARIADB
VAL_VOLUME_WP = VOLUME_WORDPRESS

up: all
	@echo "Starting containers."
	@docker compose -f ${FILE_COMPOSE} up -d

down:
	@echo "Stopping containers"
	@docker compose -f ${FILE_COMPOSE} down

all: $(DATA_MARIADB) $(DATA_WORDPRESS)

# Bununla .env içerisinde VOLUME_HOME değişkeninin olup olmadığına bak
# if [ $( grep -E 'VOLUME_HOME=".*"' ./srcs/.env | wc -l) -eq 1 ]; then echo yes; fi
# Eğer yoksa echo 'VOLUME_HOME="${DATA_MARIADB}" >> ${FILE_DOTENV} çalıştırsın.
# Eğer varsa sed -i 's/VOLUME_HOME=".*"/VOLUME_HOME="<dir>"/' srcs/.env çalıştırsın.

$(DATA_MARIADB):
	@if [ ! -d ${DATA_MARIADB} ]; then\
		echo database volume directory creating at ${DATA_MARIADB}.;\
		mkdir -p ${DATA_MARIADB} &&\
		echo "database volume directory created.";\
		echo 'Creating VOLUME_MARIADB="${DATA_MARIADB}" value on ${FILE_DOTENV}'; \
		if [ $$( grep -E '${VAL_VOLUME_DB}=".*"' ./srcs/.env | wc -l) -eq 1 ]; then \
			sed -i 's/${VAL_VOLUME_DB}=".*"/${VAL_VOLUME_DB}="$(subst /,\/,$(DATA_MARIADB))"/' srcs/.env; \
		else \
			echo '' >> $(FILE_DOTENV); \
			echo '$(VAL_VOLUME_DB)="$(DATA_MARIADB)"' >> $(FILE_DOTENV);\
		fi;\
	else\
		echo "directory exists";\
	fi
$(DATA_WORDPRESS):
	@if [ ! -d ${DATA_WORDPRESS} ]; then\
		echo database volume directory creating at ${DATA_WORDPRESS}.;\
		mkdir -p ${DATA_WORDPRESS} &&\
		echo database volume directory created.;\
		echo 'Creating ${VAL_VOLUME_WP}="${DATA_WORDPRESS}" value on ${FILE_DOTENV}'; \
		if [ $$( grep -E '${VAL_VOLUME_WP}=".*"' ./srcs/.env | wc -l) -eq 1 ]; then \
			sed -i 's/${VAL_VOLUME_WP}=".*"/${VAL_VOLUME_WP}="$(subst /,\/,$(DATA_WORDPRESS))"/' srcs/.env; \
		else \
			echo '' >> $(FILE_DOTENV); \
			echo '$(VAL_VOLUME_WP)="$(DATA_WORDPRESS)"' >> $(FILE_DOTENV);\
		fi;\
	else\
		echo "directory exists";\
	fi


clean:
	@echo "Warning. sudo mode will be requested!"
	@echo "Deleting ${DATA_MARIADB}"
	@if [ -d ${DATA_MARIADB} ]; then\
		sudo rm -rf ${DATA_MARIADB};\
	else \
		echo "${DATA_MARIADB} not found.";\
	fi
	@echo "Deleting ${DATA_WORDPRESS}"
	@if [ -d ${DATA_WORDPRESS} ]; then\
		sudo rm -rf ${DATA_WORDPRESS};\
	else \
		echo "${DATA_WORDPRESS} not found.";\
	fi

re: clean up

logs:
	@docker compose -f ${FILE_COMPOSE} logs -f

.PHONY: all up down clean re