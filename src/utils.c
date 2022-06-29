#include "utils.h"

void	put_object(t_mlx *vars, t_object *object)
{
	void	*img;
	
	if (object != NULL)
	{
		img = mlx_xpm_file_to_image(vars->mlx,object->image_addr[object->orientation],&object->width,&object->height);
		mlx_put_image_to_window (vars->mlx, vars->win, img, object->x * vars->object_size, object->y * vars->object_size);
	}
}

void	ft_exit(char *message, int err)
{
	errno = err;
	perror(message);
	exit(1);
}

int	render(void *tvars)
{
	t_mlx		*vars;
	t_object	*obj;
	int			row;
	int			col;
	int			layer;

	vars = (t_mlx *) tvars;
	row = 0;
	mlx_clear_window(vars->mlx,vars->win);
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
					put_object(vars,obj);
				layer++;
			}
			col++;
		}
		row++;
	}
	return 0;
}

t_object	get_object(char code, int x, int y)
{
	if (code == '0')
		return (create_floor(x, y));
	if (code == '1')
		return (create_wall(x, y));
	if (code == 'C')
		return (create_collectible(x, y));
	if (code == 'E')
		return (create_exit(x, y));
	if (code == 'P')
		return (create_player(x, y));
	else
		ft_exit("INVALID RULE FOR MAPPING",EINVAL);
	return (create_floor(x, y));
}

void	move_object(t_mlx *vars, t_object obj, int x, int y)
{
	t_object	***map;
	t_object	*target;
	t_object	*object;

	map = *vars->mmodel;
	target = &map[y][x][1];
	object = &map[obj.y][obj.x][1];
	if (target->is_collisionable)
	{
		object->x = x;
		object->y = y;
		*target = *object;
		//target->on_collision(vars, &target, &object);
		ft_bzero(object,sizeof(t_object));
	}
}