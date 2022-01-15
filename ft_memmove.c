/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:28:15 by emakas            #+#    #+#             */
/*   Updated: 2022/01/15 16:18:15 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (len--)
			*((unsigned char *)(dst + len)) = *((unsigned char *)(src + len));
		return (dst);
	}
	while (len--)
		*((unsigned char *)dst++) = *((unsigned char *)src++);
	return (dst);
}
