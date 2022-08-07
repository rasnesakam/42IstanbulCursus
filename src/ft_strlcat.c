/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:30:51 by emakas            #+#    #+#             */
/*   Updated: 2022/01/16 17:03:47 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = ldst;
	if (dstsize == 0)
		return (lsrc);
	if (dstsize < ldst)
		return (dstsize + lsrc);
	while (i < dstsize - 1 && *src != '\0')
	{
		*(dst + i) = *(src++);
		i++;
	}
	if (i < dstsize)
		*(dst + i) = '\0';
	while (*src != '\0')
	{
		src++;
		i++;
	}
	return (i);
}
