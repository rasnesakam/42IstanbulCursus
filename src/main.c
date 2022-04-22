#include "utils.h"

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	player	*pl;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx,1920,1080,"AMO GUS");
	pl = get_player(mlx);
	if (pl == NULL)
	{
		write(2,"Karakter oluşturulamadı\n",26);
		return (1);
	}
	put_player_mlx(mlx,mlx_win,pl);
	
	mlx_loop(mlx);
}
