#include "objects.h"

t_object	*create_floor(t_mlx mlx, int x, int y)
{
	char **images;

	images = malloc(sizeof(char *));
	images[0] = "./res/objects/floor/floor.xpm";
	return (create_object(
		mlx,
		x,
		y,
		0,
		images,
		'0'
		));
}