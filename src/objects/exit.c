/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:48:47 by emakas            #+#    #+#             */
/*   Updated: 2022/08/01 23:47:28 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

static t_object	*collsion_exit(t_mlx *vars, t_object *self, t_object *smasher)
{	
	if (smasher->otype == 'P')
	{
		if (find_ocs(vars, 'C') > 0)
			set_message(
				vars,
				ft_strjoin("DID YOU COLLECTED ALL OF DATAS?", ""));
		else
		{
			smasher = move_in_map (vars, self, smasher);
			ft_putendl_fd("The End...", 1);
			ft_putendl_fd("This little manouver is gonna cost us 51 years", 1);
			safe_exit(0, vars);
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
			images,
			'E'
			);
	exit.on_collision = collsion_exit;
	return (exit);
}
