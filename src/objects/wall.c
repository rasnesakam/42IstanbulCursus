/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:36:37 by emakas            #+#    #+#             */
/*   Updated: 2022/04/30 16:38:12 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

object	*create_wall(mlx_vars mlx, int x, int y)
{
	object	*wall;

	wall = (object *) malloc(sizeof(object));
	wall->x = x;
	wall->y = y;
	wall->image_addr = "./res/objects/wall/wall-ord.xpm";
	wall->img = mlx_xpm_file_to_image (
			mlx.mlx,
			wall->image_addr,
			&wall->width,
			&wall->height
			);
	return (wall);
}
