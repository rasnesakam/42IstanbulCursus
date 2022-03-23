CLIENT = client
SERVER = server

LIB_DIR = lib

EXTERNAL_LIBS = ft_printf libft

COMPILER = gcc

FLAG = -Wall -Wextra -Werror

$(CLIENT): 


$(SERVER):

$(LIB_DIR)/$(EXTERNAL_LIBS)/%.a:
	@echo 'making archive at location $(LIB_DIR)/$(EXTERNAL_LIBS)'