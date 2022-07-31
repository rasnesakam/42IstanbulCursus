/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:20:33 by emakas            #+#    #+#             */
/*   Updated: 2022/07/31 17:18:13 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	render_message(t_mlx *vars)
{
	static char	*msg;
	static int	index;
	static int	time;
	int			timeunit;

	timeunit = 2;
	if (msg == NULL)
		msg = "";
	if (ft_strncmp (vars->message, msg, index) != 0)
	{
		msg = "";
		index = 0;
	}
	if (index <= (int) ft_strlen (vars->message))
	{
		if (time % timeunit == 0)
			index++;
		ft_bzero (msg, ft_strlen(msg));
		msg = ft_substr (vars->message, 0, index);
	}
	time = (time + 1) % timeunit;
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0x00FFFFFF, msg);
	
}

void	render_objects(t_mlx *vars)
{
	t_object	*obj;
	int			row;
	int			col;
	int			layer;

	row = 0;
	while (row < *vars->mheight)
	{
		col = 0;
		while (col < *vars->mwidth)
		{
			layer = 0;
			while (layer < 2)
			{
				obj = &((*vars->mmodel)[row][col][layer]);
				if (obj->otype != '\0')
					put_object(vars, obj, col, row);
				layer++;
			}
			col++;
		}
		row++;
	}
}

int	render(void *tvars)
{
	t_mlx	*vars;

	vars = (t_mlx *) tvars;
	mlx_clear_window (vars->mlx, vars->win);
	render_objects (vars);
	render_message (vars);
	return (0);
}
