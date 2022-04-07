CLIENT = client
SERVER = server

LIB_DIR = lib
SRC_DIR = src

CLIEND_DIR = $(SRC_DIR)/$(CLIENT)/
CLIENT_RES = client.c  utils.c

SERVER_DIR = $(SRC_DIR)/$(SERVER)/
SERVER_RES = server.c  utils.c

LIBFT_A = $(LIB_DIR)/libft/libft.a

COMPILER = gcc

FLAG = -Wall -Wextra -Werror


all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT_A)
	@echo 'Generating $(CLIENT)'
	@$(COMPILER) $(FLAG) -o $(CLIENT) $(addprefix $(CLIEND_DIR),$(CLIENT_RES)) $(LIBFT_A)

$(SERVER): $(LIBFT_A)
	@echo 'Generating $(SERVER)'
	@$(COMPILER) $(FLAG) -o $(SERVER) $(addprefix $(SERVER_DIR),$(SERVER_RES)) $(LIBFT_A)

$(LIBFT_A):
	@echo 'Generating archives'
	@make -C $(LIB_DIR)/libft all

clean:
	@rm -f $(CLIENT) $(SERVER)
	@make -C $(LIB_DIR)/libft clean

fclean: clean
	@make -C $(LIB_DIR)/libft fclean

re: fclean all

.PHONY: all clean fclean re