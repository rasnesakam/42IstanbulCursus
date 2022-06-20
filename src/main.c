#include "utils.h"
#include "objects/objects.h"
#include "mapresolver/mapresolver.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_mlx	vars;
	int			xsize;
	int			ysize;
	t_object	***omap;
	xsize = 0;
	ysize = 0;
	if (ac == 2 && validate_map(av[1],&xsize,&ysize))
	{
		vars.mlx = mlx_init();
		//vars.win = mlx_new_window(vars.mlx,xsize * 100,ysize * 100,"AMOGUS");
		vars.mheigth = ysize;
		vars.mwidth = xsize;
		omap = create_map_model(vars,av[1]);
		vars.mmodel = &omap;
		//mlx_loop_hook(vars.mlx,render,(void *) &vars);
		//mlx_loop(vars.mlx);
	}
	else
		printf("ac:\t%d\nisvalid:\t%d",ac,validate_map(av[1],&xsize,&ysize));
	return (0);
}
