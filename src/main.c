#include <mlx.h>

int main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx,1920,1080,"AMOGUS");
	mlx_loop(mlx);
}