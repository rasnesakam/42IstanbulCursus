/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:27:10 by emakas            #+#    #+#             */
/*   Updated: 2022/01/20 18:30:35 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *s)
{
	int	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s != '\0'
		&& (*s == ' ' || *s == '\t'
			|| *s == '\n' || *s == '\v'
			|| *s == '\f' || *s == '\r'))
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
