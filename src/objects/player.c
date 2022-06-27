#include "objects.h"

struct s_params
{
	t_mlx		mlx;
	t_object	*obj;
};

int	move_player(int keycode, t_mlx *mlx)
{
	printf("keycode: %d",keycode);
	mlx->mmodel = NULL;
	return (0);
}

t_object	create_player(t_mlx mlx, int x, int y)
{
	t_object		player;
	struct s_params params;
	char			**images;

	images = malloc(sizeof(char *) * 2);
	images[0] = "./res/characters/player/amogus.xpm";
	images[1] = "./res/characters/player/amogus.xpm";
	printf("creating player\n");
	player = create_object(
		x,
		y,
		1,
		images,
		'P'
		);
	params.mlx = mlx;
	params.obj = &player;
	mlx_hook(mlx.win,2,1L<<0,move_player, &mlx);
	return (player);
}