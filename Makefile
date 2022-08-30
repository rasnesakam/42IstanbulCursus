NAME		:= philosophers

# Parent Directories
DIR_SRC		:= src/
DIR_BIN		:= bin/

# Sub Directories
DIR_ARG_CONVERTER	:= arg-converter/
DIR_ARG_PARSER		:= arg-marser/
DIR_ARG_VERIFIER	:= arg-verifier/
DIR_ENVIRONMENT		:= environment/
DIR_PHILOSOPHER		:= philosopher/
DIR_UTILS			:= utils/

# Sources
SRC_ROOT 			:= main.c
SRC_ARG_CONVERTER	:= convert-args.c
SRC_ARG_PARSER		:= collect-args.c count-args.c
SRC_ARG_VERIFIER	:= verify-args.c
SRC_ENVIRONMENT 	:= 
SRC_PHILOSOPHER 	:= 
SRC_UTILS 			:= ft-max.c ft-split.c ft-strchr.c \
						ft-strlcpy.c ft-strlen.c \
						ft-strncmp.c ft-strtrim.c \
						environment.c forks.c sleep.c \
						eat.c take*forks.c


SRC					:= $(SRC_ROOT) \
						$(addprefix $(DIR_ARG_CONVERTER), $(SRC_ARG_CONVERTER)) \
						$(addprefix $(DIR_ARG_PARSER), $(SRC_ARG_PARSER)) \
						$(addprefix $(DIR_ARG_VERIFIER), $(SRC_ARG_VERIFIER)) \
						$(addprefix $(DIR_ENVIRONMENT), $(SRC_ENVIRONMENT)) \
						$(addprefix $(DIR_PHILOSOPHER), $(SRC_PHILOSOPHER)) \
						$(addprefix $(DIR_UTILS), $(SRC_UTILS))

SRC					:= $(addprefix $(DIR_SRC), $(SRC))
BIN					:= $(subst $(DIR_SRC),$(DIR_BIN), $(SRC:.c=.o))


CC			:= gcc
CFLAGS 		+= -Wall -Werror -Wextra -c

$(NAME): $(BIN)

all: $(NAME)

re: fclean all

clean:
	@rm -rf $(DIR_BIN)

fclean: clean
	@rm -rf $(NAME)

info:
	@echo $(BIN)

$(DIR_BIN):
	mkdir -p $(DIR_BIN)

$(DIR_BIN)%.o: $(DIR_SRC)%.c $(DIR_BIN)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all re clean fclean