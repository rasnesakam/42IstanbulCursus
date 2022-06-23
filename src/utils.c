#include "utils.h"

void	put_object(t_mlx *vars, t_object *object)
{
	void	*img;
	
	if (object != NULL)
	{
		printf("object:\n\totype: %c\n\timg addr: %s",object->otype, object->image_addr[object->orientation]);
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
	printf("map boudaries: %d row, %d col\n", *vars->mheight, *vars->mwidth);
	while (row < *vars->mheight)
	{
		col = 0;
		while (col < *vars->mwidth)
		{
			layer = 0;
			while (layer < 2)
			{
				printf("rendering: (%d,%d,%d)\n",row,col,layer);
				obj = &((*vars->mmodel)[row][col][layer]);
				if (obj->otype != '\0')
					put_object(vars,obj);
				layer++;
				printf("\n");
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