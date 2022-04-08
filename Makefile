CLIENT = client
SERVER = server

LIB_DIR = lib
SRC_DIR = src
OBJ_DIR = obj

CLIENT_RES_DIR = $(addprefix $(SRC_DIR)/,$(CLIENT))
CLIENT_OBJ_DIR = $(addprefix $(OBJ_DIR)/,$(CLIENT))
CLIENT_RES = client.c  utils.c
CLIENT_OBJ = $(CLIENT_RES:.c=.o)

SERVER_RES_DIR = $(addprefix $(SRC_DIR)/,$(SERVER))
SERVER_OBJ_DIR = $(addprefix $(OBJ_DIR)/,$(SERVER))
SERVER_RES = server.c  utils.c
SERVER_OBJ = $(SERVER_RES:.c=.o)

LIBFT_A = $(LIB_DIR)/libft/libft.a

COMPILER = gcc

FLAGS = -Wall -Wextra -Werror


all: $(CLIENT) $(SERVER)

clean:
	@rm -f $(CLIENT) $(SERVER)
	@make -C $(LIB_DIR)/libft clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIB_DIR)/libft fclean

re: fclean all

$(CLIENT): $(LIBFT_A) $(addprefix $(CLIENT_OBJ_DIR)/, $(CLIENT_OBJ))
	@echo 'Generating $(CLIENT)'
	@$(COMPILER) $(FLAGS) -o $(CLIENT) $(addprefix $(CLIENT_OBJ_DIR)/, $(CLIENT_OBJ)) $(LIBFT_A)

$(SERVER): $(LIBFT_A) $(addprefix $(SERVER_OBJ_DIR)/, $(SERVER_OBJ))
	@echo 'Generating $(SERVER)'
	@$(COMPILER) $(FLAGS) -o $(SERVER) $(addprefix $(SERVER_OBJ_DIR)/, $(SERVER_OBJ)) $(LIBFT_A)

$(LIBFT_A):
	@echo 'Generating archives'
	@make -C $(LIB_DIR)/libft all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(CLIENT_OBJ_DIR): $(OBJ_DIR)
	@mkdir -p $(CLIENT_OBJ_DIR)

$(SERVER_OBJ_DIR): $(OBJ_DIR)
	@mkdir -p $(SERVER_OBJ_DIR)

$(SERVER_OBJ_DIR)%.o: $(SERVER_RES_DIR)%.c $(SERVER_OBJ_DIR)
	@$(COMPILER) $(FLAGS) -c $< -o $@

$(CLIENT_OBJ_DIR)%.o: $(CLIENT_RES_DIR)/%.c $(CLIENT_OBJ_DIR)
	@$(COMPILER) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re