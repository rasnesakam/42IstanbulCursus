/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert-args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:37:15 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 17:24:41 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_converter.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static int	ft_atoi(const char *s)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*s != '\0' && ft_isspace((int)*s))
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign *= -1;
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		res = (res * 10) + (*s - '0');
		if (res < 0 && sign == -1)
			return (0);
		else if (res < 0 && sign == 1)
			return (-1);
		s++;
	}
	return (res * sign);
}

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
