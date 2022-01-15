/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:30:51 by emakas            #+#    #+#             */
/*   Updated: 2022/01/14 16:52:58 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*(dst + i) != '\0' && i < dstsize)
		i++;
	while (i < dstsize - 1 && *src != '\0')
		*(dst + (i++)) = *(src++);
	while (*(src++) != '\0')
		i++;
	return (i);
}
