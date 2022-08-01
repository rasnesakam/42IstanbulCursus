/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:49:47 by emakas            #+#    #+#             */
/*   Updated: 2022/08/01 21:37:29 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	create_object(int x, int y, char **img, char code)
{
	t_object	object;

	object.otype = code;
	object.image_addr = img;
	object.orientation = 0;
	object.x = x;
	object.y = y;
	return (object);
}

t_object	create_null(void)
{
	t_object	object;

	object.otype = '\0';
	object.image_addr = 0;
	object.orientation = 0;
	object.x = 0;
	object.y = 0;
	object.on_collision = 0;
	return (object);
}

void	destroy_object(t_object *obj)
{
	obj->height = 0;
	obj->on_collision = 0;
	obj->orientation = 0;
	obj->otype = 0;
	obj->width = 0;
	obj->x = 0;
	obj->y = 0;
	free(obj->image_addr);
}

t_object	get_object(char code, int x, int y)
{
	if (code == '0')
		return (create_floor (x, y));
	if (code == '1')
		return (create_wall (x, y));
	if (code == 'C')
		return (create_collectible (x, y));
	if (code == 'E')
		return (create_exit (x, y));
	if (code == 'P')
		return (create_player (x, y));
	else
		return (create_null());
	return (create_floor (x, y));
}
