#include "utils.h"
#include "objects/objects.h"
#include "mapresolver/mapresolver.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_mlx		vars;
	t_object	***omap;
	int			width;
	int			height;
	
	width = 0;
	height = 0;
	if (ac == 2 && validate_map(av[1],&width,&height))
	{
		vars.mheight = &height;
		vars.mwidth = &width;
		vars.object_size = 100;
		vars.mlx = mlx_init();
		omap = create_map_model(vars,av[1]);
		vars.mmodel = &omap;
		vars.win = mlx_new_window(vars.mlx, *(vars.mwidth) * vars.object_size, *(vars.mheight) * vars.object_size, "AMOGUS");
	
		render((void *) &vars);
		//mlx_loop_hook(vars.mlx,render,(void *) &vars);
		mlx_loop(vars.mlx);
		
	}

	return (0);
}
