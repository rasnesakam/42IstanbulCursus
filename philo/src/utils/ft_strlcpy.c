/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:26:03 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 16:28:06 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

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
