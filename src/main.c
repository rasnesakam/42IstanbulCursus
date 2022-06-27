#include "utils.h"
#include "objects/objects.h"
#include "mapresolver/mapresolver.h"
#include <stdio.h>

static int	ft_close(int keycode, t_mlx *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_putendl_fd("Program terminated",1);
		exit(0);
	}
	return (0);
}

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
		mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
		mlx_loop(vars.mlx);
		
	}

	return (0);
}
