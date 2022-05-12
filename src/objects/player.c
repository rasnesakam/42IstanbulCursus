#include "objects.h"

t_object	*create_player(t_mlx mlx,int x, int y)
{
	t_object	*pl;

	pl = malloc (sizeof(t_object));
	pl->image_addr = "./res/characters/player/amogus.xpm";
	pl->x = x;
	pl->y = y;
	pl->img = mlx_xpm_file_to_image(mlx.mlx,pl->image_addr,pl->height,pl->width);
	return (pl);
}