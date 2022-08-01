/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_model.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:16:49 by emakas            #+#    #+#             */
/*   Updated: 2022/08/01 23:44:59 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapresolver.h"

t_object	*renderpoint(int lindex, int cindex, char code)
{
	t_object	*objects;

	objects = malloc (sizeof(t_object) * 2);
	if (code == '0')
	{
		objects[0] = get_object(code, cindex, lindex);
		objects[1] = create_null();
	}
	else if (code == '1')
	{
		objects[0] = create_null();
		objects[1] = get_object(code, cindex, lindex);
	}
	else
	{
		objects[0] = get_object('0', cindex, lindex);
		objects[1] = get_object(code, cindex, lindex);
	}
	return (objects);
}

t_object	**renderline(int lindex, int size, char *line)
{
	int			index;
	t_object	**objects;

	index = 0;
	objects = malloc (size * sizeof(t_object *));
	while (line[index] != '\0' && index < size)
	{
		objects[index] = renderpoint(lindex, index, line[index]);
		index++;
	}
	return (objects);
}

t_object	***create_map_model(t_mlx *mlx, char *file)
{
	int			fd;
	int			ln;
	char		*line;
	t_object	***omap;

	fd = open (file, O_RDONLY);
	if (fd < 0)
		ft_exit ("FILE COULDN'T OPEN", mlx, errno);
	ln = 0;
	omap = malloc (sizeof(t_object **) * (*mlx->mheight));
	if (omap == NULL)
		return (omap);
	while (ln < *mlx->mheight)
	{
		line = read_line (fd);
		omap[ln] = renderline(ln, *mlx->mwidth, line);
		free(line);
		ln++;
	}
	return (omap);
}
