/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:09:23 by emakas            #+#    #+#             */
/*   Updated: 2022/02/14 20:10:39 by emakas           ###   ########.fr       */
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
		{
			newstr[pos] = (*prepend)[pos];
			pos++;
		}
		len = 0;
		while ((*buffer)[len] != '\0')
			newstr[pos++] = (*buffer)[len++];
		newstr[pos] = '0';
		free (*prepend);
		free (*buffer);
		*buffer = newstr;
	}
}

void	ft_inflate(char **buffer, char **append)
{
	char	*newbuffer;
	char	*flag;
	int		readed;

	newbuffer = malloc(sizeof(char) * (ft_strlen(*buffer) + ft_strlen(*append) + 1));
	if (newbuffer == NULL)
		return ;
	flag = newbuffer;
	while(*buffer != NULL && **buffer != '\0')
	{
		*(newbuffer++) = *((*buffer)++);
	}
	while (*append != NULL && **append != '\0')
		*(newbuffer++) = *((*append)++);
	*newbuffer = '\0';
	if (*buffer != NULL)
		free(*buffer);
	if (*append != NULL)
		free(*append);
	*buffer = flag;
}

char	*ft_takexcess(char **buffer)
{
	char	*newbuffer;
	char	*returning;
	char	*stop;
	int		pos;

	stop = ft_strpos(*buffer,'\n');
	if (stop != NULL)
	{
		newbuffer = malloc(sizeof(char) * (stop - *buffer + 2));
		if (newbuffer == NULL)
			return (NULL);
		pos = 0;
		while (*buffer <= stop)
			newbuffer[pos++] = *((*buffer)++);
		newbuffer[pos] = '\0';
		returning = malloc(sizeof(char) * (ft_strpos(stop,'\0') - stop + 1));
		if (returning == NULL)
			return (NULL);
		pos = 0;
		while (*stop != '\0')
			returning[pos++] = *(stop++);
		returning[pos] = '\0';
		free(*buffer);
		*buffer = newbuffer;
		return (returning);
	}
	return (NULL);
}