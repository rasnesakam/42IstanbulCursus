NAME := philosophers

DIR_SRC := src
DIR_BIN := bin

DIRS_SRC = $(shell find $(DIR_SRC) -type d)

SRC = $(wildcard $(addsuffix /*.c, $(DIRS_SRC)))


BIN = $(subst $(DIR_SRC)/,$(DIR_BIN)/, $(SRC:.c=.o))

$(addprefix /%.o, $(DIR_BIN)): $(addprefix /%.c, $(DIR_SRC)):
	echo sa

$(NAME): $(SRC:.c=.o)

all: $(NAME)

re: fclean all

clean:

fclean: clean

info:
	@echo $(BIN)

.PHONY: all re clean fclean