/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectmodels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:14:38 by emakas            #+#    #+#             */
/*   Updated: 2022/07/30 17:17:04 by emakas           ###   ########.fr       */
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
			ft_exit ("IMAGE FILE COULDN'T FOUND", ENOENT);
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
	t_object	***map;
	t_object	*target;

	map = *vars->mmodel;
	if ((x > 0 || x < *vars->mwidth) && (y > 0 || y < *vars->mheight))
	{
		target = &(map[y][x][1]);
		if (target->on_collision != NULL)
			return (target->on_collision(vars, target, obj));
		else
		{
			*target = *obj;
			target->x = x;
			target->y = y;
			destroy_object (obj);
			return (target);
		}
	}
	return (obj);
}

t_object	**find_objects(t_mlx mlx, char otype)
{
	t_object	***map;
	t_object	**list;
	t_object	obj;
	int			row;
	int			col;

	map = *mlx.mmodel;
	row = 0;
	list = (t_object **) ft_calloc (sizeof(t_object *), 1);
	while (row < *mlx.mheight)
	{
		col = 0;
		while (col < *mlx.mwidth)
		{
			obj = map[row][col][1];
			if (obj.otype == otype)
				list_push (&list, &map[row][col][1]);
			col++;
		}
		row++;
	}
	return (list);
}

t_object	*move_in_map(t_mlx *mlx, t_object *target, t_object *source)
{
	t_object	***model;

	model = *mlx->mmodel;
	target = &model[target->y][target->x][1];
	source = &model[source->y][source->x][1];
	source->x = target->x;
	source->y = target->y;
	*target = *source;
	*mlx->movecount += 1;
	return (target);
}
