#include "utils.h"

put_object(object object, mlx mlx)
{
	mlx_put_image_to_window(mlx.mlx,mlx.win,object.img,object.x,object.y);
}