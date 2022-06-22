#include "objects.h"

t_object	create_exit(int x, int y)
{
	char **images;

	images = malloc (sizeof(char *));
	images[0] = "./res/objects/exit/exit.xpm";
	return (create_object(
		x,
		y,
		0,
		images,
		'E'
		));
}