NAME				= push_swap
CHECKER				= checker

# EXTERNALS
LIBFT				= libft/libft.a

GNL					= gnl/
SRC_GNL				= get_next_line.c get_next_line_utils.c
OBJ_GNL				= $(SRC_GNL:.c=.o)

# DIRECTORIES
DIR_SRC				= src/
DIR_ARG_CONVERTER	= arg-converter/
DIR_ARG_PARSER		= arg-parser/
DIR_ARG_VERIFIER	= arg-verifier/
DIR_CHECKER			= checker/
DIR_DATA_ANALYZER	= data-analyzer/
DIR_MAGIC_ALG		= magic-alg/
DIR_STACK			= stack/
DIR_UTILS			= utils/
DIR_VERBS			= verbs/
DIR_BIN				= bin/

# SOURCES
SRC_ROOT			= main.c
SRC_ARG_CONVERTER	= convert-args.c
SRC_ARG_PARSER		= collect-args.c count-args.c
SRC_ARG_VERIFIER	= check-args.c verify-args.c
SRC_CHECKER			= checker.c start-checker.c
SRC_DATA_ANALYZER	= get-avg.c get-max.c get-min.c
SRC_MAGIC_ALG		= abracadabra.c calc-pos.c check-sorted.c rotate-stacks.c
SRC_STACK			= stack.c
SRC_UTILS			= ft_min_max.c ft-error.c
SRC_VERBS			= push.c rotate.c rrotate.c swap.c

BIN_OBJS			= $(SRC_ROOT:.c=.o) \
						$(addprefix $(DIR_ARG_CONVERTER), $(SRC_ARG_CONVERTER:.c=.o)) \
						$(addprefix $(DIR_ARG_PARSER), $(SRC_ARG_PARSER:.c=.o)) \
						$(addprefix $(DIR_ARG_VERIFIER), $(SRC_ARG_VERIFIER:.c=.o)) \
						$(addprefix $(DIR_CHECKER), $(SRC_CHECKER:.c=.o)) \
						$(addprefix $(DIR_DATA_ANALYZER), $(SRC_DATA_ANALYZER:.c=.o)) \
						$(addprefix $(DIR_MAGIC_ALG), $(SRC_MAGIC_ALG:.c=.o)) \
						$(addprefix $(DIR_STACK), $(SRC_STACK:.c=.o)) \
						$(addprefix $(DIR_UTILS), $(SRC_UTILS:.c=.o)) \
						$(addprefix $(DIR_VERBS), $(SRC_VERBS:.c=.o)) \

BIN_DIRS			= $(addprefix $(DIR_BIN), $(DIR_ARG_CONVERTER)) \
						$(addprefix $(DIR_BIN), $(DIR_ARG_PARSER)) \
						$(addprefix $(DIR_BIN), $(DIR_ARG_VERIFIER)) \
						$(addprefix $(DIR_BIN), $(DIR_CHECKER)) \
						$(addprefix $(DIR_BIN), $(DIR_DATA_ANALYZER)) \
						$(addprefix $(DIR_BIN), $(DIR_MAGIC_ALG)) \
						$(addprefix $(DIR_BIN), $(DIR_STACK)) \
						$(addprefix $(DIR_BIN), $(DIR_UTILS)) \
						$(addprefix $(DIR_BIN), $(DIR_VERBS)) 

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -Ilibft/src -Ignl -c

$(DIR_BIN)%.o: $(DIR_SRC)%.c
	@echo "Compiling binary: $@"
	@$(CC) $(CFLAGS) -o $@ $<

$(BIN_DIRS):
	@echo "Creating file: $@"
	@mkdir -p $@

$(NAME): $(BIN_DIRS) $(addprefix $(DIR_BIN), $(BIN_OBJS))
	@$(CC) -Llibft -lft -o $(NAME) $(BIN_OBJS)

re: fclean all	

all: $(NAME)

clean:
	rm -rf $(DIR_BIN)

fclean: clean
	rm -rf $(NAME) $(CHECKER)

.PHONY: all clean fclean re