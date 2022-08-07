/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:06:06 by emakas            #+#    #+#             */
/*   Updated: 2022/01/12 19:06:08 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ns;
	int		i;

	ns = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ns == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		ns[i++] = *s1++;
	while (*s2 != '\0')
		ns[i++] = *s2++;
	ns[i] = '\0';
	return (ns);
}
