/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:09:23 by emakas            #+#    #+#             */
/*   Updated: 2022/02/13 23:13:59 by emakas           ###   ########.fr       */
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

int	ft_strlen(char *c)
{
	int	count;

	count = 0;
	if (c != NULL)
		while (c[count] != '\0')
			count++;
	return (count);
}

void	ft_prepend_if_exists(char **prepend, char **buffer)
{
	char	*newstr;
	int		len;
	int		pos;

	if (*prepend != NULL)
	{
		newstr = malloc (sizeof(char)
				* (ft_strlen (*prepend) + ft_strlen (*buffer) + 1));
		if (newstr == NULL)
			return ;
		pos = 0;
		while ((*prepend)[pos] != '\0')
			newstr[pos] = (*prepend)[pos++];
		len = 0;
		while ((*buffer)[len] != '\0')
			newstr[pos++] = (*buffer)[len++];
		newstr[pos] = '0';
		free (*prepend);
		free (*buffer);
		*buffer = newstr;
	}
}

void	ft_inflate(int fd, char **buffer)
{

}

void	ft_takexcess(char **buffer, char **prepend)
{
	
}