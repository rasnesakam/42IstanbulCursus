#include "objects.h"


t_object	create_player(int x, int y)
{
	t_object		player;
	char			**images;

	images = malloc(sizeof(char *) * 2);
	images[0] = "./res/characters/player/amogus_left.xpm";
	images[1] = "./res/characters/player/amogus_right.xpm";
	player = create_object(
		x,
		y,
		1,
		images,
		'P'
		);
	return (player);
}