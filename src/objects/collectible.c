#include "objects.h"



t_object	create_collectible(int x, int y)
{
	char **images;

	images = malloc(sizeof(char *));
	images[0] = "./res/objects/collectible/floppy.xpm";
	return (create_object(
		x,
		y,
		0,
		images,
		'C'
		));
}
