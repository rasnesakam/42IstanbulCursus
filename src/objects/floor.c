#include "objects.h"

t_object	create_floor(int x, int y)
{
	t_object	floor;
	char		**images;

	images = malloc(sizeof(char *));
	images[0] = "./res/objects/floor/floor.xpm";
	floor = create_object(
		x,
		y,
		0,
		images,
		'0'
		);
	floor.on_collision = NULL;
	return (floor);
}