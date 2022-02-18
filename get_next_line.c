/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:30:24 by emakas            #+#    #+#             */
/*   Updated: 2022/02/17 23:25:23 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_read(int fd, char **buffer, char **prepend)
{
	int		readed;
	char	*tmp;

	readed = BUFFER_SIZE;
	if (*prepend != NULL)
	{
		ft_merge(prepend, *buffer);
		free(*prepend);
	}
	while (ft_strpos(*buffer, '\n') == NULL && readed == BUFFER_SIZE )
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (tmp == NULL)
			return ;
		readed = read(fd,tmp,BUFFER_SIZE);
		tmp[BUFFER_SIZE] = '\0';
		if (readed < BUFFER_SIZE){
			ft_setnull(tmp,readed);
		}
		ft_merge(buffer, tmp);
		free(tmp);
	}
}



char	*get_next_line(int fd)
{
	static char	*prepend;
	char		*buffer;

	buffer = NULL;
	prepend = NULL;
	ft_read(fd, &buffer, &prepend);
	//buffer = ft_get_line(buffer,&prepend);
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
