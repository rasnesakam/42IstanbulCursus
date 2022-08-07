/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:31:13 by emakas            #+#    #+#             */
/*   Updated: 2022/01/16 16:34:26 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	size_t	ix;

	ix = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (ix < dstsize - 1 && src[ix] != '\0')
	{
		dest[ix] = src[ix];
		ix++;
	}
	dest[ix] = '\0';
	while (src[ix] != '\0')
		ix++;
	return (ix);
}
