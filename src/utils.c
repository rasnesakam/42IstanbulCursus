#include "utils.h"

void	put_object(t_mlx vars, t_object object)
{
	mlx_put_image_to_window (vars.mlx, vars.win, object.img, object.x, object.y);
}