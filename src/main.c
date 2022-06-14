#include "utils.h"
#include "objects/objects.h"
#include "mapresolver/mapresolver.h"

int main(int ac, char **av)
{
	t_mlx	vars;
	int			xsize;
	int			ysize;

	if (ac == 2 && validate_map(av[1],&xsize,&ysize))
	{
		vars.mlx = mlx_init();
		
		vars.win = mlx_new_window(vars.mlx,xsize,ysize,"AMOGUS");
		vars.mmodel = create_map_model(vars,av[1]);
		mlx_loop_hook(vars.mlx,render,(void *) &vars);

		mlx_loop(vars.mlx);
	}
	
}
