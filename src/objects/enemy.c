#include "objects.h"

t_object	*create_enemy(t_mlx mlx, int x, int y)
{
	char **images;
	images = malloc (sizeof(char *) * 2);
	images[0] = "./res/characters/enemy/enemy-left.xpm";
	images[1] = "./res/characters/enemy/enemy-right.xpm";
	return (create_object(
		mlx,
		x,
		y,
		1,
		images,
		'D'
		));
}