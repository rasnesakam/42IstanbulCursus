/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:28:03 by emakas            #+#    #+#             */
/*   Updated: 2022/07/26 07:28:54 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapresolver.h"

int	validate_map(char *maddr, int *xsize, int *ysize)
{
	int		fd;
	char	*line;
	char	*tline;

	fd = openorext (maddr);
	line = read_line (fd);
	if (line == NULL)
		return (0);
	*xsize = ft_strlen (line);
	*ysize = 0;
	check_all_wall (line);
	while (line != NULL)
	{
		if (*xsize != (int) ft_strlen (line))
			ft_exit ("MAP SHOULD BE RECTANGULAR", EINVAL);
		if (line[0] != '1' || line[*xsize - 1] != '1')
			ft_exit ("MAP SHOULD BE SURROUNDED BY WALLS", EINVAL);
		line = read_line (fd);
		if (line != NULL)
			tline = line;
		*ysize += 1;
	}
	check_all_wall (tline);
	return (1);
}
