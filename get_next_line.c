/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:30:24 by emakas            #+#    #+#             */
/*   Updated: 2022/02/14 20:31:46 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*ft_readline(int fd)
{
	int		readed;
	char	*newbuffer;
	char	*tmp;

	readed = BUFFER_SIZE;
	newbuffer = NULL;
	while (readed == BUFFER_SIZE && ft_strpos (newbuffer, '\n') == NULL)
	{
		tmp = malloc (sizeof(char) * BUFFER_SIZE + 1);
		if (tmp != NULL)
			return (NULL);
		readed = read (fd, tmp, BUFFER_SIZE);
		printf("BUFFER: %s\n TEMP: %s\n",newbuffer,tmp);
		*(tmp + BUFFER_SIZE + 1 - (BUFFER_SIZE - readed)) = '\0';
		printf("BUFFER: %s\n TEMP: %s\n",newbuffer,tmp);
		ft_inflate(&newbuffer, &tmp);
		printf("BUFFER: %s\n TEMP: %s\n",newbuffer,tmp);
	}
	return (newbuffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*prepend;

	buffer = NULL;
	prepend = NULL;
	ft_prepend_if_exists(&prepend, &buffer); // Prepends the excess from previous readed data
	printf("BUFFER: %s\n",buffer);
	buffer = ft_readline(fd); // reads the string that contains ENDL or terminator
	printf("BUFFER: %s\n",buffer);
	prepend = ft_takexcess(&buffer); // takes chars after '\n' from buffer and stores them in 'prepend'
	printf("BUFFER: %s\n",buffer);
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
