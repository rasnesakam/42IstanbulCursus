#include "utils.h"
#include "objects/objects.h"
#include "handlers.h"
#include "mapresolver/mapresolver.h"
#include <stdio.h>

static int	ft_handle(int keycode, t_mlx *vars)
{
	
	handle_exit(keycode, vars);
	handle_player(keycode,vars);
	return (0);
}

int main(int ac, char **av)
{
	t_mlx		vars;
	t_object	***omap;
	t_object	**collectibles;
	int			width;
	int			height;
	int			state;
	
	width = 0;
	height = 0;
	state = 1;
	if (ac == 2 && validate_map(av[1],&width,&height))
	{
		vars.mheight = &height;
		vars.mwidth = &width;
		vars.state = &state;
		vars.object_size = 100;
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, *(vars.mwidth) * vars.object_size, *(vars.mheight) * vars.object_size, "AMOGUS");
		vars.message = "COLLECT ALL OF DATAS!";
		omap = create_map_model(vars,av[1]);
		vars.mmodel = &omap;
		vars.player = find_objects(vars,'P')[0];
		collectibles = find_objects(vars,'C');
		vars.collectibles = &collectibles;
		
		mlx_loop_hook(vars.mlx,render,(void *) &vars);
		mlx_hook(vars.win, 2, 1L<<0, ft_handle, &vars);
		
		mlx_loop(vars.mlx);
		
	}

	return (0);
}
