/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:30:24 by emakas            #+#    #+#             */
/*   Updated: 2022/02/24 20:07:16 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_prepend(char **prepend, char **buffer)
{
	if (*prepend != NULL)
	{
		ft_merge (prepend, *buffer);
		free (*buffer);
		ft_merge (buffer, *prepend);
		free (*prepend);
		*prepend = NULL;
	}
}

void	ft_read(int fd, char **buffer, char **prepend)
{
	int		readed;
	char	*tmp;

	readed = BUFFER_SIZE;
	tmp = NULL;
	ft_prepend (prepend, buffer);
	while (ft_strpos (*buffer, '\n')
		== NULL && readed == BUFFER_SIZE)
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (tmp == NULL)
			return ;
		readed = read (fd, tmp, BUFFER_SIZE);
		tmp[BUFFER_SIZE] = '\0';
		if (readed < BUFFER_SIZE)
			ft_setnull (tmp, readed);
		if (readed == -1)
			ft_setnull (tmp, 0);
		ft_merge (buffer, tmp);
		free (tmp);
	}
}

void	ft_get_line(char **buffer, char **prepend)
{
	char	*newstr;
	char	*stop;

	newstr = NULL;
	stop = ft_strpos (*buffer, '\n');
	if (stop == NULL)
		stop = ft_strpos(*buffer, '\0');
	if (*stop == '\n' && stop[1])
	{
		ft_merge (prepend, &stop[1]);
		stop[1] = '\0';
	}
	ft_merge (&newstr, *buffer);
	free (*buffer);
	*buffer = newstr;
}

char	*get_next_line(int fd)
{
	static char	*prepend;
	char		*buffer;

	buffer = NULL;
	if (fd >= 0)
	{
		ft_read (fd, &buffer, &prepend);
		ft_get_line (&buffer, &prepend);
	}
	if (ft_len (buffer) > 0)
		return (buffer);
	free (buffer);
	return (NULL);
}
