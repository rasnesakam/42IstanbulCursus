NAME		= so_long

CFLAGS		+= -g -Wall -Wextra -Werror -I./mlx -I./libft
LFLAGS		= -g -L./mlx -lmlx -L./libft -lft -framework OpenGL -framework AppKit -o $(NAME)
CC			= gcc

MLX			= mlx/libmlx.a
LIBFT		= libft/libft.a

SRCDIR		= src/
ODIR		= obj/

EXTDIR		= ext/
MRDIR		= mapresolver/
OBJDIR		= objects/
UDIR		= utils/

EXTERNALS	= get_next_line_utils.c get_next_line.c
MRESOLVERS	= create_map_model.c openorext.c \
				read_line.c validate_map.c
OBJECTS 	= collectible.c exit.c floor.c objects.c player.c wall.c
UTILS		= list.c objectmodels.c render.c utils.c safext.c
MAIN		= handlers.c main.c

ALL_SRC		= $(addprefix $(join $(ODIR),$(EXTDIR)), $(EXTERNALS)) \
				$(addprefix $(join $(ODIR),$(MRDIR)), $(MRESOLVERS)) \
				$(addprefix $(join $(ODIR),$(OBJDIR)), $(OBJECTS)) \
				$(addprefix $(join $(ODIR),$(UDIR)), $(UTILS)) \
				$(addprefix $(ODIR), $(MAIN)) 

ALL_OBJ		= $(patsubst %.c,%.o,$(ALL_SRC))



$(NAME): $(LIBFT) $(MLX) $(ODIR) $(ALL_OBJ)
	$(CC) $(LFLAGS)  -o $(NAME) $(ALL_OBJ) libft/libft.a

$(MLX):
	@make -C ./mlx all

$(LIBFT):libft
	@git submodule init
	@git submodule update
	@make -C ./libft all

$(ODIR):
	mkdir -p $(ODIR)
	mkdir -p $(addprefix $(ODIR),$(EXTDIR))
	mkdir -p $(addprefix $(ODIR),$(MRDIR))
	mkdir -p $(addprefix $(ODIR),$(OBJDIR))
	mkdir -p $(addprefix $(ODIR),$(UDIR))

$(ODIR)%.o: $(SRCDIR)%.c
	@echo "GENERATING: " $@
	@$(CC) $(CFLAGS) -c -o $@ $< 

all: $(NAME)

clean:
	@echo "\nREMOVING MLX OBJECTS \n"
	@make -C ./mlx clean
	@echo "\nREMOVING LIBFT OBJECTS \n"
	@make -C ./libft clean
	@rm -rf $(ODIR)

fclean: clean
	@echo "\nFULL CLEAN FOR LIBFT\n"
	@make -C ./libft fclean
	@echo "\nREMOVING $(NAME)\n"
	@rm  -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
