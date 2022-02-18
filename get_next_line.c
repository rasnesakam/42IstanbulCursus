/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:30:24 by emakas            #+#    #+#             */
/*   Updated: 2022/02/18 18:14:49 by emakas           ###   ########.fr       */
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
	tmp = NULL;
	if (*prepend != NULL)
	{
		ft_merge(prepend,*buffer);
		free(*buffer);
		ft_merge(buffer,*prepend);
		free(*prepend);
		*prepend = NULL;
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

void	ft_get_line(char **buffer, char **prepend)
{
	char	*newstr;
	char	*stop;

	newstr = NULL;
	stop = ft_strpos(*buffer,'\n');
	if (stop == NULL)
		stop = ft_strpos(*buffer,'\0');
	if (*stop == '\n' && stop[1])
	{
		ft_merge(prepend,&stop[1]);
		stop[1] = '\0';
	}
	ft_merge(&newstr,*buffer);
	free(*buffer);
	*buffer = newstr;
}

char	*get_next_line(int fd)
{
	static char	*prepend;
	char		*buffer;

	buffer = NULL;
	if (fd > 0)
	{
		ft_read(fd, &buffer, &prepend); // reads untill occure '\n' char or eof
		ft_get_line(&buffer,&prepend); // clears after '\n' and stores them to prepend
	}
	return (buffer);
}




int	main(void)
{
int	fd;

fd = open("exammple.txt", O_RDONLY);
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

