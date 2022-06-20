#include "objects.h"

void	collectible_collision(t_object *self, t_object *obj)
{
	printf("%c",self->otype);
}

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
		images,
		'C'
		));
}
