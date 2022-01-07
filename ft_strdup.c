/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:40:40 by emakas            #+#    #+#             */
/*   Updated: 2022/01/07 17:40:42 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cs;
	int		i;

	i = 0;
	cs = malloc(sizeof(char) * ft_strlen(s));
	if (cs == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		cs[i] = s[i];
		i++;
	}
	return (cs);
}
