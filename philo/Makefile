NAME		:= philo

# Parent Directories
DIR_SRC		:= src/
DIR_BIN		:= bin/

# Sub Directories
DIR_ARG_CONVERTER	:= arg-converter/

DIR_ARG_PARSER		:= arg-parser/

DIR_ARG_VERIFIER	:= arg-verifier/

DIR_CONCURRENCY		:= concurrency/

DIR_ENVIRONMENT		:= environment/

DIR_PHILOSOPHER		:= philosopher/

DIR_UTILS			:= utils/

DIR_LIST			:= $(DIR_ARG_CONVERTER) \
						$(DIR_ARG_PARSER) \
						$(DIR_ARG_VERIFIER) \
						$(DIR_CONCURRENCY) \
						$(DIR_ENVIRONMENT) \
						$(DIR_PHILOSOPHER) \
						$(DIR_UTILS)

# Sources
SRC_ROOT 			:= main.c

SRC_ARG_CONVERTER	:= convert-args.c

SRC_ARG_PARSER		:= collect-args.c \
						count-args.c

SRC_ARG_VERIFIER	:= verify-args.c

SRC_CONCURRENCY		:= call-bifunction.c \
						call-synchronized.c \
						get-int-sync.c \
						get-synchronized.c \
						int-function.c

SRC_ENVIRONMENT 	:= environments.c \
						forks.c

SRC_PHILOSOPHER 	:= philosopher.c

SRC_UTILS 			:= all-ejected.c \
						check-starve.c \
						destroy-global-mutex.c \
						ft_isdigit.c \
						ft-max.c \
						ft-split.c \
						ft-strchr.c \
						ft-strlcpy.c \
						ft-strlen.c \
						ft-strncmp.c \
						ft-strtrim.c \
						ft-wait.c \
						get-global-mutex.c \
						get-timestamp.c \
						philo-eat.c \
						philo-print.c \
						philo-sleep.c \
						philo-think.c



SRC					:= $(SRC_ROOT) \
						$(addprefix $(DIR_ARG_CONVERTER), $(SRC_ARG_CONVERTER)) \
						$(addprefix $(DIR_ARG_PARSER), $(SRC_ARG_PARSER)) \
						$(addprefix $(DIR_ARG_VERIFIER), $(SRC_ARG_VERIFIER)) \
						$(addprefix $(DIR_CONCURRENCY), $(SRC_CONCURRENCY)) \
						$(addprefix $(DIR_ENVIRONMENT), $(SRC_ENVIRONMENT)) \
						$(addprefix $(DIR_PHILOSOPHER), $(SRC_PHILOSOPHER)) \
						$(addprefix $(DIR_UTILS), $(SRC_UTILS))

SRC					:= $(addprefix $(DIR_SRC), $(SRC))
BIN					:= $(subst $(DIR_SRC),$(DIR_BIN), $(SRC:.c=.o))


# Print Colors
RED					:= \033[0;31m
GREEN				:= \033[1;32m

CC			:= gcc
CFLAGS 		+= -Wall -Werror -Wextra -pthread -g #-fsanitize=thread 

all: $(NAME)

$(NAME): $(DIR_BIN) $(BIN)
	@echo "$(GREEN)creating executable file"
	@$(CC) $(CFLAGS) $(BIN) -o $(NAME)

re: fclean all

clean:
	@echo "$(RED)removing bin file"
	@rm -rf $(DIR_BIN)

fclean: clean
	@echo "$(RED)removing executable file"
	@rm -rf $(NAME)

$(DIR_BIN):
	@echo "$(GREEN)creating binary folders"
	@mkdir -p $(DIR_BIN) $(addprefix $(DIR_BIN), $(DIR_LIST))

$(DIR_BIN)%.o: $(DIR_SRC)%.c
	@echo "$(GREEN)creating binary file from: $(basename $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all re clean fclean

# echo $(SRC) | awk '{split($$0, array); for (el in array){print el}}'