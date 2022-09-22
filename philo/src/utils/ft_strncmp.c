/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:27:42 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 16:36:38 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

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
