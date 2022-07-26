/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:49:47 by emakas            #+#    #+#             */
/*   Updated: 2022/07/26 07:52:04 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <stdio.h>

t_object	create_object(int x, int y, int orientation, char **img, char code)
{
	t_object	object;

	object.otype = code;
	object.image_addr = img;
	object.orientation = orientation;
	object.x = x;
	object.y = y;
	return(object);
}

t_object	create_null(void)
{
	t_object	object;

	object.otype = '\0';
	object.image_addr = NULL;
	object.orientation = 0;
	object.x = 0;
	object.y = 0;
	object.on_collision = NULL;
	return(object);
}

void	destroy_object(t_object *obj)
{
	obj->height = 0;
	obj->image_addr = NULL;
	obj->on_collision = NULL;
	obj->orientation = 0;
	obj->otype = '\0';
	obj->width = 0;
	obj->x = 0;
	obj->y = 0;
}
