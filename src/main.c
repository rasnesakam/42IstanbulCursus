#include "utils.h"

int main(void)
{
	mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx,1920,1080,"AMOGUS");
	


	
	mlx_loop(mlx.mlx);
}
