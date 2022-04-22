NAME = so_long

CFLAGS += -Wall -Wextra -Werror -I./mlx
LFLAGS = -framework OpenGL -framework AppKit -L./mlx -lmlx
CC = gcc

SRCDIR = src/
SRC = main.c characters.c

OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

$(NAME): $(OBJ)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

print:
	@echo $(OBJ)