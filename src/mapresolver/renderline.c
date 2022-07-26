/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:26:00 by emakas            #+#    #+#             */
/*   Updated: 2022/07/26 07:26:18 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapresolver.h"

t_object	**renderline(int lindex, int size, char *line)
{
	int			index;
	t_object	**objects;

	index = 0;
	objects = malloc (size * sizeof(t_object *));
	while (line[index] != '\0' && index < size)
	{
		objects[index] = renderpoint (lindex, index, line[index]);
		index++;
	}
	return (objects);
}
