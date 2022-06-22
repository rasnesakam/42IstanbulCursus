#include "utils.h"

void	put_object(t_mlx *vars, t_object *object)
{
	void	*img;
	
	if (object != NULL)
	{
		img = mlx_xpm_file_to_image(vars->mlx,object->image_addr[object->orientation],&object->width,&object->height);
		mlx_put_image_to_window (vars->mlx, vars->win, img, object->x, object->y);
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
	t_mlx	*vars;
	int		row;
	int		col;
	int		z;

	vars = (t_mlx *) tvars;
	row = 0;
	col = 0;
	z = 0;
	while (row < *vars->mheigth)
	{
		while (col < *vars->mwidth)
		{
			while (z < 2)
			{
				printf("rendering object\n");
				put_object(vars,&(vars->mmodel[0])[row][col][z]);
				z++;
			}
			col++;
		}
		row++;
	}
	return 0;
}

t_object	get_object(char code, int x, int y)
{
	t_object	obj;

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
	return (obj);
}