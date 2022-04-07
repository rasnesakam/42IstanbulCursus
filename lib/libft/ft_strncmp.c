/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:31:35 by emakas            #+#    #+#             */
/*   Updated: 2022/01/16 17:03:24 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 != '\0' || *s2 != '\0') && n--)
	{
		if ((unsigned char)*s1 < (unsigned char)*s2)
			return (-1);
		else if ((unsigned char)*s1 > (unsigned char)*s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}
