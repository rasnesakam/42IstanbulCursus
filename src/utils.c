#include "utils.h"

void	put_object(t_mlx vars, t_object *object)
{
	if (object != NULL)
		mlx_put_image_to_window (vars.mlx, vars.win, object->img, object->x, object->y);
}

void	ft_exit(char *message, int err)
{
	errno = err;
	perror(message);
	exit(1);
}