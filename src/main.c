#include "utils.h"
#include "chars/player/player.h"

int main(void)
{
	mlx_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,1920,1080,"AMOGUS");
	
	object *player = create_player(vars,0,0);

	put_object(vars,*player);

	
	mlx_loop(vars.mlx);
}
