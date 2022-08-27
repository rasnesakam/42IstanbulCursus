NAME				= push_swap
CHECKER				= checker

# EXTERNALS
LIBFT				= libft/libft.a



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
SRC_DATA_ANALYZER	= get-avg.c get-max.c get-min.c
SRC_MAGIC_ALG		= abracadabra.c calc-pos.c check-sorted.c rotate-stacks.c
SRC_STACK			= stack.c
SRC_UTILS			= ft_min_max.c ft-error.c
SRC_VERBS			= push.c rotate.c rrotate.c swap.c

BIN_OBJS			= $(SRC_ROOT:.c=.o) \
						$(addprefix $(DIR_ARG_CONVERTER), $(SRC_ARG_CONVERTER:.c=.o)) \
						$(addprefix $(DIR_ARG_PARSER), $(SRC_ARG_PARSER:.c=.o)) \
						$(addprefix $(DIR_ARG_VERIFIER), $(SRC_ARG_VERIFIER:.c=.o)) \
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
CFLAGS				= -Wall -Werror -Wextra -Ilibft/src -c



# ================================================================
# BONUS
DIR_BONUS			= bonus/
BNS_DIR_BIN			= bbin/
SRC_CHECKER				= checker_bonus.c start-checker_bonus.c
BNS_SRC_ARG_CONVERTER	= convert-args_bonus.c
BNS_SRC_ARG_PARSER		= collect-args_bonus.c count-args_bonus.c
BNS_SRC_ARG_VERIFIER	= check-args_bonus.c verify-args_bonus.c
BNS_SRC_CHECKER			= checker_bonus.c start-checker_bonus.c
BNS_SRC_STACK			= stack_bonus.c
BNS_SRC_UTILS			= ft_min_max_bonus.c ft-error_bonus.c get_next_line.c get_next_line_utils.c
BNS_SRC_VERBS			= push_bonus.c rotate_bonus.c rrotate_bonus.c swap_bonus.c

BBIN_OBJS			= $(addprefix $(DIR_ARG_CONVERTER), $(BNS_SRC_ARG_CONVERTER:.c=.o)) \
						$(addprefix $(DIR_ARG_PARSER), $(BNS_SRC_ARG_PARSER:.c=.o)) \
						$(addprefix $(DIR_ARG_VERIFIER), $(BNS_SRC_ARG_VERIFIER:.c=.o)) \
						$(addprefix $(DIR_CHECKER), $(BNS_SRC_CHECKER:.c=.o)) \
						$(addprefix $(DIR_STACK), $(BNS_SRC_STACK:.c=.o)) \
						$(addprefix $(DIR_UTILS), $(BNS_SRC_UTILS:.c=.o)) \
						$(addprefix $(DIR_VERBS), $(BNS_SRC_VERBS:.c=.o)) \

BBIN_DIRS			= $(addprefix $(BNS_DIR_BIN), $(DIR_ARG_CONVERTER)) \
						$(addprefix $(BNS_DIR_BIN), $(DIR_ARG_PARSER)) \
						$(addprefix $(BNS_DIR_BIN), $(DIR_ARG_VERIFIER)) \
						$(addprefix $(BNS_DIR_BIN), $(DIR_CHECKER)) \
						$(addprefix $(BNS_DIR_BIN), $(DIR_STACK)) \
						$(addprefix $(BNS_DIR_BIN), $(DIR_UTILS)) \
						$(addprefix $(BNS_DIR_BIN), $(DIR_VERBS)) 



# DEFAULT RULES
all: $(LIBFT) $(NAME) bonus

$(NAME): $(LIBFT) $(BIN_DIRS) $(addprefix $(DIR_BIN), $(BIN_OBJS))
	@$(CC) -Llibft -lft -o $(NAME) $(addprefix $(DIR_BIN), $(BIN_OBJS))

$(CHECKER): $(LIBFT) $(addprefix $(GNL), $(SRC_GNL:.c=.o)) $(BBIN_DIRS) $(addprefix $(BNS_DIR_BIN), $(BBIN_OBJS))

# CREATE LIBRARY
$(LIBFT): libs
	@echo "Making libft"
	@make -C libft all


# MANDATORY BINARIES
$(DIR_BIN)%.o: $(DIR_SRC)%.c
	@echo "Compiling binary: $@"
	@$(CC) $(CFLAGS) -o $@ $<

$(BIN_DIRS):
	@echo "Creating file: $@"
	@mkdir -p $@


# BONUS BINARIES
$(BNS_DIR_BIN)%.o: $(DIR_BONUS)%.c
	@echo "Compiling binary: $@"
	@$(CC) $(CFLAGS) -o $@ $<

$(BBIN_DIRS):
	@echo "Creating file: $@"
	@mkdir -p $@


#PHONIES
bonus: $(LIBFT) $(addprefix $(GNL), $(SRC_GNL)) $(CHECKER)
	@$(CC) -Llibft -lft -o $(CHECKER) $(addprefix $(BNS_DIR_BIN), $(BBIN_OBJS)) \
		$(addprefix $(GNL), $(SRC_GNL:.c=.o))

re: fclean all	

clean:
	@echo "Removing libft binaries"
	@make -C libft clean
	@rm -rf $(DIR_BIN) $(BNS_DIR_BIN) $(addprefix $(GNL), $(SRC_GNL:.c=.o))

fclean: clean
	@echo "Removing libft archives"
	@make -C libft fclean
	@rm -rf $(NAME) $(CHECKER)

libs:
	@git submodule init
	@git submodule update

.PHONY: all clean fclean re bonus libs