/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:32:32 by emakas            #+#    #+#             */
/*   Updated: 2022/01/15 16:04:57 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	ix;
	unsigned char	*cs1;
	unsigned char	*cs2;

	ix = 0;
	cs1 = (unsigned char *) s1;
	cs2 = (unsigned char *) s2;
	while (n-- > 0)
	{
		if(cs1[ix] != cs2[ix])
			return (cs1[ix] - cs2[ix]);
		ix++;
	}
	return (0);
}
