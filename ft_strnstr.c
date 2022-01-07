/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:31:52 by emakas            #+#    #+#             */
/*   Updated: 2022/01/07 12:31:54 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int	i;
	int	j;

	if (needle[0] == '\0')
		return (haystack);
	i = 0;
	while (haystack[i] != '\0' && n--)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return (&haystack[i + j]);
		}
	}
	return (NULL);
}
