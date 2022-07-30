/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:49:09 by emakas            #+#    #+#             */
/*   Updated: 2022/07/30 13:45:17 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	create_floor(int x, int y)
{
	t_object	floor;
	char		**images;

	images = malloc (sizeof(char *));
	images[0] = "./res/objects/floor/floor.xpm";
	floor = create_object (
			x,
			y,
			images,
			'0'
			);
	floor.on_collision = NULL;
	return (floor);
}
