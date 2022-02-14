/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:30:24 by emakas            #+#    #+#             */
/*   Updated: 2022/02/13 22:30:19 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*prepend;

	ft_prepend_if_exists(&prepend, &buffer); // Prepends the excess from previous readed data 
	ft_inflate(fd,&buffer); // inflates buffer with readed file datas that given file descriptor 'fd'
	ft_takexcess(&buffer,&prepend); // takes chars after '\n' from buffer and stores them in 'prepend'

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
