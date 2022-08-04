/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:28:03 by emakas            #+#    #+#             */
/*   Updated: 2022/08/04 16:47:09 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapresolver.h"

static void	check_all_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			ft_exit("MAP SHOULD BE SURROUNDED BY WALLS", NULL, EINVAL);
		i++;
	}
}

static void	ft_control(char *line, int size)
{
	if (size != (int)ft_strlen(line))
		ft_exit("MAP SHOULD BE RECTANGULAR", NULL, EINVAL);
	if (line[0] != '1' || line[size - 1] != '1')
		ft_exit("MAP SHOULD BE SURROUNDED BY WALLS", NULL, EINVAL);
	while (line && *line)
	{
		if (ft_strchr("10PCE",*line) == NULL)
			ft_exit("INVALID CHARACTER", NULL, EINVAL);
		line++;
	}
}

static char	*firstline(int fd, int *xsize, int *ysize)
{
	char	*line;

	line = read_line(fd);
	if (line == NULL)
		return (0);
	*xsize = ft_strlen(line);
	*ysize = 0;
	return (line);
}

int	validate_map(char *maddr, int *xsize, int *ysize)
{
	int		fd;
	char	*line;
	char	*tline;

	fd = openorext (maddr);
	line = firstline (fd, xsize, ysize);
	if (ft_strlen(line) == 0)
		ft_exit("INVALID MAP", NULL, EINVAL);
	check_all_wall (line);
	while (line != NULL)
	{
		if (ft_strchr (line, '\n') == NULL)
			check_all_wall(tline);
		free(line);
		line = ft_strtrim(line, "\n");
		ft_control(line,*xsize);
		free(line);
		line = get_next_line (fd);
		if (line != NULL)
			tline = line;
		*ysize += 1;
	}
	return (1);
}
