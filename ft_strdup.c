/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:40:40 by emakas            #+#    #+#             */
/*   Updated: 2022/01/08 13:54:42 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cs;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	cs = malloc(sizeof(char) * len);
	if (cs == NULL)
		return (NULL);
	ft_strlcpy (cs, s, len);
	return (cs);
}
