/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:18:06 by emakas            #+#    #+#             */
/*   Updated: 2022/01/19 20:57:54 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ns;
	char	*fst;

	ns = malloc(sizeof(char) * (len + 1));
	fst = ns;
	if (ns == NULL)
		return (NULL);
	if (start < (unsigned int)ft_strlen(s))
		while (s[start] != '\0' && len-- > 0)
			*ns++ = s[start++];
	*ns = '\0';
	return (fst);
}
