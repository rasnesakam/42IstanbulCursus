#include "utils.h"

void	put_object(t_mlx *vars, t_object *object)
{
	void	*img;
	printf("putting object:\n");
	printf("\tmlx: %s\n",(char *)vars->mlx);
	printf("\twin: %s\n",(char *)vars->win);
	printf("\timg orientation: %d\n",object->orientation);
	printf("\timg address: %s\n",object->image_addr[object->orientation]);
	printf("\tox: %d\n", object->x);
	printf("\toy: %d\n", object->y);
	
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
	while (row < vars->mheigth)
	{
		while (col < vars->mwidth)
		{
			while (z < 2)
			{
				printf("rendering object\n");
				put_object(vars,&(vars->mmodel[row][col][z]));
				z++;
			}
			col++;
		}
		row++;
	}
	return 0;
}