/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:19:22 by emakas            #+#    #+#             */
/*   Updated: 2022/07/30 14:19:24 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "objects/objects.h"
#include "handlers.h"
#include "mapresolver/mapresolver.h"
#include <stdio.h>

static int	ft_handle(int keycode, t_mlx *vars)
{
	handle_exit (keycode, vars);
	handle_player (keycode, vars);
	return (0);
}

void	check_model(t_mlx vars)
{
	int	collectiblecount;
	int	exitcount;
	int	spawncount;

	collectiblecount = list_size (find_objects (vars, 'C'));
	exitcount = list_size (find_objects (vars, 'E'));
	spawncount = list_size (find_objects (vars, 'P'));
	if (!collectiblecount || !exitcount || !spawncount)
		ft_exit(
			"MAP SHOULD INCLUDE AT LEAST ONE FOR EVERY C, E AND P",
			EINVAL);
}

t_mlx	create(int *height, int *width, char *file)
{
	t_mlx		vars;

	vars.mmodel = (t_object ****) ft_calloc (sizeof(void *), 1);
	vars.collectibles = (t_object ***) ft_calloc (sizeof(void *), 1);
	vars.mheight = height;
	vars.mwidth = width;
	vars.object_size = 100;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(
			vars.mlx,
			*(vars.mwidth) * vars.object_size,
			*(vars.mheight) * vars.object_size,
			"AMOGUS");
	vars.message = "COLLECT ALL OF DATAS!";
	*vars.mmodel = create_map_model (vars, file);
	vars.player = find_objects (vars, 'P')[0];
	*vars.collectibles = find_objects (vars, 'C');
	return (vars);
}

int	main(int ac, char **av)
{
	t_mlx		vars;
	int			width;
	int			height;
	int			state;

	width = 0;
	height = 0;
	state = 1;
	if (ac == 2 && validate_map (av[1], &width, &height))
	{
		vars = create (&height, &width, av[1]);
		check_model (vars);
		mlx_loop_hook (vars.mlx, render, (void *) &vars);
		mlx_hook (vars.win, 2, 1L << 0, ft_handle, &vars);
		mlx_loop (vars.mlx);
	}
	return (0);
}
