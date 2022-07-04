NAME = so_long

CFLAGS += -g -Wall -Wextra -Werror -I./mlx -I./libft
LFLAGS = -L./mlx -Llibft -lmlx -framework OpenGL -framework AppKit -o $(NAME)
CC = gcc

SRCDIR = src/
SRC = main.c utils.c handlers.c \
		$(addprefix mapresolver/, $(SRC_MAPRESOLVER)) \
		$(addprefix objects/, $(SRC_OBJECTS)) \
		$(addprefix ext/, $(SRC_EXT))
SRC_MAPRESOLVER = mapresolver.c
SRC_OBJECTS = collectible.c enemy.c exit.c floor.c objects.c player.c wall.c
SRC_EXT = get_next_line_utils.c get_next_line.c
CHARS = chars/
ASDASD = -I ./src/mapresolver/mapresolver.h ./src/objects/objects.h ./src/*.h
OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
LIB = mlx libft

HEADERS = mapresolver/ objects/ src/

$(NAME): $(LIB) $(OBJ)
	$(CC) $(LFLAGS)  -o $(NAME) $(addprefix $(OBJDIR), $(SRC:.c=.o)) libft/libft.a

all: $(NAME)

clean:
	@make -C ./mlx clean
	@rm -r $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/mapresolver
	mkdir -p $(OBJDIR)/objects
	mkdir -p $(OBJDIR)/ext


$(addprefix $(OBJDIR),$(CHARS)):
	mkdir -p $@

$(OBJDIR)%.o: $(SRCDIR)%.c $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(addprefix $(OBJDIR),$(CHARS))%.o : $(addprefix $(SRCDIR),$(CHARS))%.c
	$(CC) $(CFLAGS) -c -o $@ $<

