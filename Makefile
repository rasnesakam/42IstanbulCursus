CLIENT = client
SERVER = server

LIB_DIR = lib
SRC_DIR = src

CLIEND_DIR = $(SRC_DIR)/$(CLIENT)/
CLIENT_RES = client.c client.h utils.c

SERVER_DIR = $(SRC_DIR)/$(SERVER)/
SERVER_RES = server.c server.h utils.c

LIBFT_A = $(LIB_DIR)/libft/libft.a

COMPILER = gcc

FLAG = -Wall -Wextra -Werror

$(CLIENT): $(LIBFT_A)
	@$(COMPILER) $(FLAG) $(addprefix $(CLIEND_DIR),$(CLIENT_RES)) $(LIBFT_A) -o $(CLIENT)

$(SERVER): $(LIBFT_A)
	@$(COMPILER) $(FLAG) $(addprefix $(SERVER_DIR),$(SERVER_RES)) $(LIBFT_A) -o $(SERVER)

$(LIBFT_A): 
	@make -C $(LIB_DIR)/libft all

all: $(CLIENT) $(SERVER)

clean:
	@rm -f $(CLIENT) $(SERVER)
	@make -C $(LIB_DIR)/libft clean

fclean: clean
	@make -C $(LIB_DIR)/libft fclean

re: fclean all

.PHONY: all clean fclean re