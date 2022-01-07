/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:28:15 by emakas            #+#    #+#             */
/*   Updated: 2022/01/07 14:28:17 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, void *src, size_t len)
{
	if (dst == src)
		return (dst);
	if (d > s)
	{
		while (len--)
			*((char *)(dst + len)) = *((char *)(src + len));
		return (dst);
	}
	while (len--)
		*((char *)dst++) = *((char *)src++);
	return (dst);
}
