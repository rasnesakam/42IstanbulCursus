/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:30:24 by emakas            #+#    #+#             */
/*   Updated: 2022/02/10 22:22:13 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*s;
	static char	*prepend;
	int			ri;

	buffer = NULL;
	if (prepend != NULL)
		buffer = ft_expand (prepend, buffer);
	prepend = NULL;
	s = malloc (sizeof(char) * BUFFER_SIZE);
	ri = read (fd, s, BUFFER_SIZE);
	while (ri == BUFFER_SIZE && ft_strpos (s, '\n') == NULL)
	{
		buffer = ft_expand (buffer, s);
		ri = read (fd, s, BUFFER_SIZE);
	}
	if (ri <= BUFFER_SIZE && ri > 0)
		buffer = ft_expand (buffer, ft_substr (s, 0, ri));
	if (ft_strpos (buffer, '\n'))
	{
		prepend = ft_strpos (buffer, '\n') + 1;
		buffer = ft_substr (buffer, 0, ft_strposi (buffer, 0, '\n'));
	}
	return (buffer);
}

int	main(void)
{
	int	fd;

	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
		printf("Failed to open...\n");

	char *buff;
	for (int i = 1; i <= 9; i++)
	{
		buff = get_next_line(fd);
		printf("LINE-%d: %s",i,buff);
	}
	return (0);
}
