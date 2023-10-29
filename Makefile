DIR_DATA = $(HOME)/data
DATA_MARIADB = ${DIR_DATA}/db
DATA_WORDPRESS = ${DIR_DATA}/wp
DIR_COMPOSE = srcs/docker-compose.yml


up: all
	@echo "Starting containers."
	@docker compose -f ${DIR_COMPOSE} up -d

down:
	@echo "Stopping containers"
	@docker compose -f ${DIR_COMPOSE} down

all: $(DATA_MARIADB) $(DATA_WORDPRESS)

$(DATA_MARIADB):
	@if [ ! -d ${DATA_MARIADB} ]; then\
		echo database volume directory creating at ${DATA_MARIADB}.;\
		mkdir -p ${DATA_MARIADB} &&\
		echo database volume directory created.;\
	else\
		echo "directory exists";\
	fi
$(DATA_WORDPRESS):
	@if [ ! -d ${DATA_WORDPRESS} ]; then\
		echo database volume directory creating at ${DATA_WORDPRESS}.;\
		mkdir -p ${DATA_WORDPRESS} &&\
		echo database volume directory created.;\
	else\
		echo "directory exists";\
	fi

clean:
	@echo "Deleting ${DATA_MARIADB}"
	@if [[ -d ${DATA_MARIADB} ]]; then\
		rm -rf ${DATA_MARIADB};\
	else \
		echo "${DATA_MARIADB} not found.";\
	fi
	@echo "Deleting ${DATA_WORDPRESS}"
	@if [[ -d ${DATA_WORDPRESS} ]]; then\
		rm -rf ${DATA_WORDPRESS};\
	else \
		echo "${DATA_WORDPRESS} not found.";\
	fi

re: clean up

.PHONY: all up down clean re