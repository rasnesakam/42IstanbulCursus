#include "utils.h"

player	*get_player(void *mlx)
{
	player	*pl;

	pl = malloc(sizeof(player));
	pl->image_addr = "./res/characters/player/amogus.xpm";
	pl->height = 200;
	pl->width = 200;
	pl->x = 0;
	pl->y = 0;
	pl->img = mlx_xpm_file_to_image(mlx,pl->image_addr,&pl->width,&pl->height);
	if (pl->img == NULL)
		return (NULL);
	return (pl);
}

int		get_pl_posx(player *pl, int time)
{
	return (time * pl->x);
}

int		get_pl_posy(player *pl,int time)
{
	return (time * pl->y);
}

void	put_player_mlx(void *mlx, void *mlx_win, player *pl)
{
	mlx_put_image_to_window(mlx,mlx_win,pl->img,get_pl_posx(pl,0),get_pl_posy(pl,0));
}