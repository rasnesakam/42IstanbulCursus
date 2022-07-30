NAME		= so_long

CFLAGS		+= -Wall -Wextra -Werror -I./mlx -I./libft
LFLAGS		= -L./mlx -lmlx -L./libft -lft -framework OpenGL -framework AppKit -o $(NAME)
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
MRESOLVERS	= check_all_wall.c create_map_model.c openorext.c \
				read_line.c renderline.c renderpoint.c validate_map.c
OBJECTS 	= collectible.c exit.c floor.c objects.c player.c wall.c
UTILS		= list.c objectmodels.c render.c utils.c 
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
	@make -C ./libft all

libft:
	@git submodule update

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
	@make -C ./mlx clean
	@make -C ./libft clean
	@rm -r $(OBJDIR)

fclean: clean
	@make -C ./mlx fclean
	@make -C ./libft fclean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
