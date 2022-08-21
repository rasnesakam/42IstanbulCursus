/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert-args_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 01:46:56 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 18:43:33 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_converter_bonus.h"

int	*convert_args(int ac, char **av)
{
	int	*list;
	int	index;

	if (ac > 0)
	{
		list = malloc(sizeof(int) * ac);
		index = 0;
		while (index < ac)
		{
			list[index] = ft_atoi(av[index]);
			index++;
		}
		return (list);
	}
	return (NULL);
}
