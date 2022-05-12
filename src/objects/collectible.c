#include "objects.h"

t_object	*create_collectible(t_mlx mlx, int x, int y)
{
	char **images;

	images = malloc(sizeof(char *));
	images[0] = "./res/objects/collectible/floppy.xpm";
	return (create_object(
		mlx,
		x,
		y,
		0,
		images
		));
}