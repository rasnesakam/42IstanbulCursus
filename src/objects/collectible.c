/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:43:14 by emakas            #+#    #+#             */
/*   Updated: 2022/07/30 14:38:08 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

static t_object	*on_collision(t_mlx *mlx, t_object *self, t_object *smasher)
{
	int	ccount;

	list_remove (mlx->collectibles, self);
	ccount = list_size (*mlx->collectibles);
	if (ccount > 0)
		mlx->message = ft_strjoin ("REMAINED DATAS: ", ft_itoa (ccount));
	else
		mlx->message = "CONGRATULATIONS. UNIVERSE HAS BEEN SAVED. MOVE TO EXIT";
	smasher = move_in_map (mlx, self, smasher);
	destroy_object(self);
	return (smasher);
}

t_object	create_collectible(int x, int y)
{
	t_object	obj;
	char		**images;

	images = malloc(sizeof(char *));
	images[0] = "./res/objects/collectible/floppy.xpm";
	obj = create_object(
			x,
			y,
			images,
			'C'
			);
	obj.on_collision = on_collision;
	return (obj);
}
