/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:36:37 by emakas            #+#    #+#             */
/*   Updated: 2022/06/20 16:47:30 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	*create_wall(t_mlx mlx, int x, int y)
{
	char **images;

	images = malloc(sizeof(char *));
	images[0] = "./res/objects/wall/wall-ord.xpm";
	return (create_object(
			mlx,
			x,
			y,
			0,
			images,
			'1'
		));
}
