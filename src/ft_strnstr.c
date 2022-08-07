/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:31:52 by emakas            #+#    #+#             */
/*   Updated: 2022/01/19 20:00:26 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int		i;
	int		j;
	size_t	limit;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && n--)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			limit = n;
			while ((haystack[i + j] == needle[j]) && limit-- > 0)
				j++;
			if (needle[j] == '\0'
				|| ((haystack[i + j] == needle[j]) && needle[j + 1] == '\0'))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
