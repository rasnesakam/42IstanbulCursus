NAME			= push_swap

DIR_SRC			= src
DIR_ARG_PARSER	= arg-parser
DIR_STACK		= stack
DIR_VERBS		= verbs

DIR_BIN			= bin

SRC_ROOT		= main
SRC_ARG_PARSER	= collect-args count-args
SRC_STACK		= asd
SRC_VERBS		= asd

CC				= gcc
CFLAGS			= asdasd

$(NAME):
	gcc src/*.c src/arg-converter/*.c src/arg-parser/*.c src/arg-verifier/*.c src/magic-alg/*.c src/stack/*.c src/utils/*.c src/verbs/*.c libft/libft.a

all: $(NAME)

clean:

fclean:

.PHONY: all clean fclean