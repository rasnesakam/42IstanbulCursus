/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:48:47 by emakas            #+#    #+#             */
/*   Updated: 2022/07/26 07:48:52 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

static t_object	*collsion_exit(t_mlx *vars, t_object *self, t_object *smasher)
{
	if (smasher->otype == 'P')
	{
		if (list_size (*vars->collectibles) > 0)
			vars->message = "DID YOU COLLECTED ALL OF DATAS?";
		else
		{
			smasher = move_objects (vars, self, smasher);
			mlx_destroy_window (vars->mlx, vars->win);
			ft_putendl_fd ("The End...", 1);
			ft_putendl_fd ("This little manouver is gonna cost us 51 years", 1);
			exit (0);
		}
	}
	return (smasher);
}

t_object	create_exit(int x, int y)
{
	t_object	exit;
	char		**images;

	images = malloc (sizeof(char *));
	images[0] = "./res/objects/exit/exit.xpm";
	exit = create_object (
			x,
			y,
			0,
			images,
			'E'
			);
	exit.on_collision = collsion_exit;
	return (exit);
}
