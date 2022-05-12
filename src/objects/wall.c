/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:36:37 by emakas            #+#    #+#             */
/*   Updated: 2022/05/12 13:28:54 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	*create_wall(t_mlx mlx, int x, int y)
{
	t_object	*wall;

	wall = (t_object *) malloc(sizeof(t_object));
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
