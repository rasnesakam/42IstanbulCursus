#include "objects.h"
#include <stdio.h>

t_object	*create_object(t_mlx mlx, int x, int y, int orientation, char **img, char code){
	t_object	*object;

	object = (t_object *) malloc(sizeof(t_object));
	object->otype = code;
	object->image_addr = img;
	object->orientation = orientation;
	mlx.mheigth = 6;
	object->x = x;
	object->y = y;

	return(object);
}