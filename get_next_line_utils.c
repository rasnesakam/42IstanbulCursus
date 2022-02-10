/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:09:23 by emakas            #+#    #+#             */
/*   Updated: 2022/02/10 22:16:26 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strpos(char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char) c)
			return (s);
		s++;
	}
	if (*s == (char) c)
		return (s);
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s != NULL && *(s++) != '\0')
		count++;
	return (count);
}

char	*ft_expand(const char *s1, const char *s2)
{
	char	*new_buffer;
	int		pos;

	new_buffer = (char *) malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_buffer == NULL)
		return (NULL);
	pos = 0;
	while (s1 != NULL && *s1 != '\0')
	{
	new_buffer[pos] = (char) *s1;
	pos++;
	s1++;
	}
	while (s2 != NULL && *s2 != '\0')
	{
		new_buffer[pos] = (char) *s2;
		pos++;
		s2++;
	}
	new_buffer[pos] = '\0';
	return (new_buffer);
}

int	ft_strposi(char *str, int start, int search)
{
	int	index;

	index = start;
	if (str == NULL)
		return (-1);
	while (str[index] != '\0')
		if (str[index++] == (char) search)
			return (--index);
	if (str[index] == (char) search)
		return (index);
	return (-1);
}

char	*ft_substr(char *s, int start, int end)
{
	char	*newstr;
	int		pos;

	pos = 0;
	newstr = malloc(sizeof(char) * (end - start + 2));
	if (newstr == NULL)
		return (NULL);
	while (start <= end)
	{
	newstr[pos++] = s[start++];
	}
	newstr[pos] = '\0';
	return (newstr);
}
