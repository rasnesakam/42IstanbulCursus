/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectmodels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:14:38 by emakas            #+#    #+#             */
/*   Updated: 2022/08/01 23:51:57 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	put_object(t_mlx *vars, t_object *object, int x, int y)
{
	void	*img;

	if (object->otype != '\0')
	{
		img = mlx_xpm_file_to_image(
				vars->mlx,
				object->image_addr[object->orientation],
				&object->width, &object->height);
		if (img == NULL)
			ft_exit ("IMAGE FILE COULDN'T FOUND", vars, ENOENT);
		mlx_put_image_to_window(
			vars->mlx,
			vars->win,
			img,
			x * vars->object_size,
			y * vars->object_size);
		mlx_destroy_image (vars->mlx, img);
	}
}

t_object	*move_object(t_mlx *vars, t_object *obj, int x, int y)
{
	t_object	*target;

	if ((x > 0 || x < *vars->mwidth) && (y > 0 || y < *vars->mheight))
	{
		target = &((*vars->mmodel)[y][x][1]);
		if (target->on_collision != NULL)
			return (target->on_collision(vars, target, obj));
		else
		{
			*target = *obj;
			target->x = x;
			target->y = y;
			*obj = create_null();
			ft_putstr_fd("Move count: ", 1);
			ft_putnbr_fd((*vars->movecount)++, 1);
			ft_putendl_fd("", 1);
			return (target);
		}
	}
	return (obj);
}

int	find_ocs(t_mlx *mlx, char otype)
{
	t_object	*obj;
	int			row;
	int			col;
	int			count;

	row = 0;
	count = 0;
	while (row < *mlx->mheight)
	{
		col = 0;
		while (col < *mlx->mwidth)
		{
			obj = &(*mlx->mmodel)[row][col][1];
			if (obj->otype == otype)
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

t_object	*find_object(t_mlx *mlx, char otype)
{
	t_object	*obj;
	int			row;
	int			col;

	row = 0;
	while (row < *mlx->mheight)
	{
		col = 0;
		while (col < *mlx->mwidth)
		{
			obj = &(*mlx->mmodel)[row][col][1];
			if (obj->otype == otype)
				return (obj);
			col++;
		}
		row++;
	}
	return (NULL);
}

t_object	*move_in_map(t_mlx *mlx, t_object *target, t_object *source)
{
	target = &(*mlx->mmodel)[target->y][target->x][1];
	source = &(*mlx->mmodel)[source->y][source->x][1];
	source->x = target->x;
	source->y = target->y;
	destroy_object(target);
	*target = *source;
	*source = create_null();
	ft_putstr_fd("Move count: ", 1);
	ft_putnbr_fd((*mlx->movecount)++, 1);
	ft_putendl_fd("", 1);
	return (target);
}
