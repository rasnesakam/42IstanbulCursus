/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:22:56 by emakas            #+#    #+#             */
/*   Updated: 2022/08/01 23:48:24 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	list_size(t_object **list)
{
	int	count;

	count = 0;
	while (list && (list[count] != NULL))
		count++;
	return (count);
}

void	list_remove(t_object ***reflist, t_object *ref)
{
	t_object	**nlist;
	int			index;
	int			nindex;

	nlist = (t_object **) ft_calloc (sizeof(t_object *), list_size (*reflist));
	if (!nlist)
		return ;
	index = 0;
	nindex = 0;
	while ((*reflist)[index] != NULL)
	{
		if ((*reflist)[index] != ref)
		{
			nlist[nindex] = (*reflist)[index];
			nindex++;
		}
		index++;
	}
	free (*reflist);
	*reflist = nlist;
}
