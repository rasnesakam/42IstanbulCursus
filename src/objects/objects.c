#include "objects.h"
#include <stdio.h>

t_object	create_object(int x, int y, int orientation, char **img, char code){
	t_object	object;

	object.otype = code;
	object.image_addr = img;
	object.orientation = orientation;
	object.x = x;
	object.y = y;

	return(object);
}