# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 19:15:18 by emakas            #+#    #+#              #
#    Updated: 2022/02/24 19:15:20 by emakas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_print_format.c ft_putchar.c ft_puthexlow.c ft_puthexup.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_putudecimal.c ft_printf.c

SRCDIR = src/

SOURCE = $(addprefix $(SRCDIR), $(SRC))

OBJDIR = objs/

OBJ = $(SRC:.c=.o)

OBJECT = $(addprefix $(OBJDIR), $(OBJ))

CC = gcc

FLAGS = -Wall -Wextra -Werror

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo 'generating out: $@'
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJECT)
	@echo 'generating archive: $@'
	@ar rc $(NAME) $(OBJECT)

all: $(NAME)

clean:
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re