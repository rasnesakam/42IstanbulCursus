/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:24:26 by emakas            #+#    #+#             */
/*   Updated: 2022/08/01 14:03:21 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapresolver.h"

char	*read_line(int fd)
{
	char	*line;
	char	*tmp;

	line = get_next_line (fd);
	tmp = line;
	if (line != NULL)
	{
		line = ft_strtrim(line, "\n");
		free(tmp);
	}
	return (line);
}
