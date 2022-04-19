#include "utils.h"

int main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx,1920,1080,"AMO GUS");

	player player;

	player.img = mlx_new_image(mlx,1920,1080);

	player.addr = mlx_get_data_addr(player.img, &player.bits_pp, &player.line_len, &player.endian);

	mlx_loop(mlx);
}



void my_mlx_pixel_put(player *pl, int x, int y, int col)
{
	char	*dst;

	dst = pl->addr + ( y * pl->line_len + x * (pl->bits_pp / 8) );

	*(unsigned int *)dst = col;
}