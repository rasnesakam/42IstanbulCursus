NAME = so_long

CFLAGS += -Wall -Wextra -Werror -I./mlx
LFLAGS = -framework OpenGL -framework AppKit -L./mlx -lmlx
CC = gcc

SRCDIR = src/
SRC = main.c utils.c

CHARS = chars/

OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
LIB = libmlx.a

$(NAME): $(LIB) $(OBJ)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	@make -C ./mlx clean
	@rm -r $(OBJDIR)

$(LIB):
	@echo Lıbrary archive generating
	@make -C ./$@ all

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(addprefix $(OBJDIR),$(CHARS)):
	mkdir -p $@

$(OBJDIR)%.o: $(SRCDIR)%.c $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(addprefix $(OBJDIR),$(CHARS))%.o : $(addprefix $(SRCDIR),$(CHARS))%.c
	$(CC) $(CFLAGS) -c -o $@ $<

