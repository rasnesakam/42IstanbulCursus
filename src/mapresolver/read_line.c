/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:24:26 by emakas            #+#    #+#             */
/*   Updated: 2022/07/31 15:58:47 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapresolver.h"

char	*read_line(int fd)
{
	char	*line;

	line = get_next_line (fd);
	if (line != NULL)
		line = ft_strtrim (line, "\n");
	return (line);
}
