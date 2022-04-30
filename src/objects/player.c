#include "objects.h"

object	*create_player(mlx_vars mlx,int x, int y)
{
	object	*pl;

	pl = malloc (sizeof(object));
	pl->image_addr = "./res/characters/player/amogus.xpm";
	pl->x = x;
	pl->y = y;
	pl->img = mlx_xpm_file_to_image(mlx.mlx,pl->image_addr,pl->height,pl->width);
	return (pl);
}