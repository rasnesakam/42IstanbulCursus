#include "utils.h"
#include "objects/objects.h"
#include "handlers.h"
#include "mapresolver/mapresolver.h"
#include <stdio.h>

static int	ft_handle(int keycode, t_mlx *vars)
{
	
	handle_exit(keycode, vars);
	if (keycode == 36) {
		ft_putendl_fd("Enter key pressed",1);
	}
	else
	{
		ft_putstr_fd("Pressed key: ",1);
		ft_putnbr_fd(keycode,1);
		ft_putendl_fd("",1);
	}
	return (0);
}

t_object	*find_object(t_mlx mlx, char otype)
{
	int			row;
	int			col;
	t_object	***map;

	row = 0;
	map = *mlx.mmodel;
	while (row < *mlx.mwidth)
	{
		col = 0;
		while (col < *mlx.mheight)
		{
			if (map[row][col][1].otype == otype)
				return (&map[row][col][1]);
			col++;
		}
		row++;
	}
	return (NULL);
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
		vars.win = mlx_new_window(vars.mlx, *(vars.mwidth) * vars.object_size, *(vars.mheight) * vars.object_size, "AMOGUS");
		printf("Win arg at MAIN: %s\n",(char *)vars.win);
		omap = create_map_model(vars,av[1]);
		vars.mmodel = &omap;
		vars.player = find_object(vars,'P');
		render((void *) &vars);
		//mlx_loop_hook(vars.mlx,render,(void *) &vars);
		mlx_hook(vars.win, 2, 1L<<0, ft_handle, &vars);
		mlx_loop(vars.mlx);
		
	}

	return (0);
}
