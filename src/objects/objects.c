#include "objects.h"

t_object	*create_object(t_mlx mlx, int x, int y, int orientation, char **img){
	t_object	*object;

	object = (t_object *) malloc(sizeof(t_object));
	object->image_addr = img;
	object->orientation = orientation;
	object->img = mlx_xpm_file_to_image (
			mlx.mlx,
			object->image_addr[object->orientation],
			&object->width,
			&object->height
			);
	object->x = x;
	object->y = y;
	return(object);
}