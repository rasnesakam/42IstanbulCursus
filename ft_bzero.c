/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:27:23 by emakas            #+#    #+#             */
/*   Updated: 2022/01/14 16:07:34 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	cnt;
	char			*str;

	str = s;
	cnt = 0;
	while (cnt < n)
	{
		str[cnt++] = '\0';
	}
}
