/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:27:03 by emakas            #+#    #+#             */
/*   Updated: 2022/07/26 07:27:38 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapresolver.h"

t_object	*renderpoint(int lindex, int cindex, char code)
{
	t_object	*objects;

	objects = ft_calloc (sizeof(t_object), 2);
	if (code == '0')
	{
		objects[0] = get_object (code, cindex, lindex);
		objects[1] = create_null ();
	}
	else if (code == '1')
	{
		objects[0] = create_null ();
		objects[1] = get_object (code, cindex, lindex);
	}
	else
	{
		objects[0] = get_object ('0', cindex, lindex);
		objects[1] = get_object (code, cindex, lindex);
	}
	return (objects);
}
