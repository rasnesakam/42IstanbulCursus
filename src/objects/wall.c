/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:36:37 by emakas            #+#    #+#             */
/*   Updated: 2022/06/22 19:58:57 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	create_wall(int x, int y)
{
	char **images;

	images = malloc(sizeof(char *));
	images[0] = "./res/objects/wall/wall-ord.xpm";
	return (create_object(
			x,
			y,
			0,
			images,
			'1'
		));
}
