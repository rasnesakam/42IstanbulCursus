NAME	= libft.a

SRC_DIR = src/

BIN_DIR = bin/

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		  ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		  ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BSRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		  ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c

OBJS	= $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

BOBJS	= $(addprefix $(BIN_DIR), $(BSRCS:.c=.o))

CC		= gcc

CFLAGS	+= -Wall -Wextra -Werror -I ./ -c


$(NAME): $(BIN_DIR) $(OBJS)
	ar rc $(NAME) $(OBJS)

$(BIN_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

all: $(NAME) bonus

bonus: $(BIN_DIR) $(BOBJS)
	ar rc $(NAME) $(BOBJS)

clean:
	rm -rf $(BIN_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus
