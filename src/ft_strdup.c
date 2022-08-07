/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:40:40 by emakas            #+#    #+#             */
/*   Updated: 2022/01/15 23:36:22 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cs;
	int		len;

	len = ft_strlen(s);
	cs = malloc(sizeof(char) * len + 1);
	if (cs == NULL)
		return (NULL);
	ft_strlcpy (cs, (char *)s, len + 1);
	return (cs);
}
