#include "utils.h"
#include "objects/objects.h"
#include "mapresolver.h"

int main(int ac, char **av)
{
	mlx_vars	vars;
	int			xsize;
	int			ysize;

	if (ac == 2)
	{
		vars.mlx = mlx_init();
		if (validate_map(av[1],xsize,ysize))
		{
			vars.win = mlx_new_window(vars.mlx,xsize,ysize,"AMOGUS");
	
		}
	}
	
	mlx_loop(vars.mlx);
}
