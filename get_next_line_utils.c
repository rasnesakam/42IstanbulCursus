/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:09:23 by emakas            #+#    #+#             */
/*   Updated: 2022/02/17 23:24:48 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_merge(char **s1, char *s2)
{
	char	*newstr;
	int		pos;
	int		ix;

	newstr = malloc(sizeof(char) * (ft_len(*s1) + ft_len(s2) + 1));
	if (newstr == NULL)
		return ;
	pos = 0;
	ix = 0;
	while (*s1 && *s1[ix] != '\0')
		newstr[pos++] = *s1[ix++];
	ix = 0;
	while (s2 && s2[ix] != '\0')
		newstr[pos++] = s2[ix++];
	newstr[pos] = '\0';
	if (*s1 != NULL)
		free(*s1);
	*s1 = newstr;
}

char	*ft_strpos(char *str, int c)
{
	int pos;

	pos = 0;
	while (str != NULL && str[pos] != '\0'
		&& str[pos] != (char) c)
		pos++;
	if (str && str[pos] == (char) c)
		return (&str[pos]);
	return (NULL);
}

void	ft_setnull(char *s, int after)
{
	while (s != NULL && *(s + after) != '\0')
		*(s + after++) = '\0';
}

int	ft_len(char *str)
{
	int count;

	count = 0;
	while (str && str[count] != '\0')
		count++;
	return (count);
}