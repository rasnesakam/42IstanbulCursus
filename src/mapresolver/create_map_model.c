/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_model.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:16:49 by emakas            #+#    #+#             */
/*   Updated: 2022/07/26 07:17:59 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapresolver.h"

t_object	***create_map_model(t_mlx mlx, char *file)
{
	int			fd;
	int			ln;
	char		*line;
	t_object	***omap;

	fd = open (file, O_RDONLY);
	ln = 0;
	omap = malloc (((sizeof(t_object) * 2) * *mlx.mwidth) * *mlx.mheight);
	if (omap == NULL)
		return (omap);
	while (ln < *mlx.mheight)
	{
		line = read_line (fd);
		omap[ln] = renderline (ln, *mlx.mwidth, line);
		ln++;
	}
	return (omap);
}
