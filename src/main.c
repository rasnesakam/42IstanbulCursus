#include "utils.h"
#include "objects/objects.h"
#include "mapresolver/mapresolver.h"
#include <stdio.h>

void update(t_mlx vars)
{
	vars.mheigth = 6;
}

int main(int ac, char **av)
{
	t_mlx	vars;
	int			xsize;
	int			ysize;

	xsize = 0;
	ysize = 0;
	if (ac == 2 && validate_map(av[1],&xsize,&ysize))
	{
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx,xsize * 100,ysize * 100,"AMOGUS");
		vars.mheigth = ysize;
		vars.mwidth = xsize;
		create_map_model(&vars,av[1]);
		mlx_loop_hook(vars.mlx,render,(void *) &vars);
		mlx_loop(vars.mlx);
		update(vars);
		printf("%d\n",vars.mheigth);
	}
	else
		printf("ac:\t%d\nisvalid:\t%d",ac,validate_map(av[1],&xsize,&ysize));
	return (0);
}
