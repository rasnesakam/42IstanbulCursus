#include "objects.h"

t_object	*create_player(t_mlx mlx,int x, int y)
{
	char **images;

	images = malloc(sizeof(char *) * 2);
	images[0] = "./res/characters/player/amogus-left.xpm";
	images[1] = "./res/characters/player/amogus-right.xpm";
	return (create_object(
		mlx,
		x,
		y,
		1,
		images,
		'P'
		));
}