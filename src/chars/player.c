#include "player.h"
#include <stdlib.h>

object	*create_player(mlx mlx,int x, int y)
{
	object	*pl;

	pl = malloc (sizeof(object));
	pl->image_addr = "./res/characters/player/amogus.xpm";
	pl->img = mlx_xpm_file_to_image(mlx.mlx,pl->image_addr,pl->height,pl->width);
	return (pl);
}