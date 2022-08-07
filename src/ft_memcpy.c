/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:29:38 by emakas            #+#    #+#             */
/*   Updated: 2022/01/15 16:15:17 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, void *src, unsigned int n)
{
	char			*cdst;
	const char		*csrc;
	unsigned int	cnt;

	cdst = dst;
	csrc = src;
	cnt = 0;
	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	while (cnt < n)
	{
		cdst[cnt] = csrc[cnt];
		cnt++;
	}
	return (dst);
}
