#include "utils.h"
#include "objects/objects.h"
#include "mapresolver/mapresolver.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_mlx	vars;
	t_object	***omap;
	
	if (ac == 2 && validate_map(av[1],vars.mwidth,vars.mheigth))
	{
		vars.mlx = mlx_init();
		omap = create_map_model(vars,av[1]);
		vars.mmodel = &omap;
		//vars.win = mlx_new_window(vars.mlx, *(vars.mwidth) * 100,*(vars.mheight) * 100,"AMOGUS");
	
		//mlx_loop_hook(vars.mlx,render,(void *) &vars);
		//mlx_loop(vars.mlx);
		int y = 0;

		while (y < *vars.mheigth)
		{
			int x = 0;
			while (x < *vars.mwidth)
			{
				int z = 0;
				while (z < 2)
				{
					t_object object = vars.mmodel[0][y][x][z];
					if ((void *)&object != NULL)
						printf("%c",object.otype);
					z++;
				}
				x++;
			}
			printf("\n");
			y++;
		}
	}

	return (0);
}
