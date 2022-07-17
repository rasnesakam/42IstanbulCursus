
#include "objects.h"

#define PASS(x) (void)(x)

static t_object	*on_collision(t_mlx *mlx, t_object *self, t_object *smasher)
{
	int ccount;
	list_remove(mlx->collectibles,self);
	ccount = list_size(*mlx->collectibles);
	
	printf("ici\n");
	if (ccount > 0)
	{
		mlx->message = ft_strjoin("REMAINED DATAS: ",ft_itoa(ccount));
	}
	else
	{
		mlx->message = "CONGRATULATIONS. UNIVERSE HAS BEEN SAVED. MOVE TO EXIT";
	}
	
	t_object	***model;
	t_object	*target;
	t_object	*source;
	model = *mlx->mmodel;
	target = &model[self->y][self->x][1];
	source = &model[smasher->y][smasher->x][1];
	source->x = target->x;
	source->y = target->y;
	*target = *source;
	destroy_object(source);
	return (target);
}

t_object	create_collectible(int x, int y)
{
	t_object obj;
	char **images;

	images = malloc(sizeof(char *));
	images[0] = "./res/objects/collectible/floppy.xpm";
	obj = create_object(
		x,
		y,
		0,
		images,
		'C'
		);
	obj.on_collision = on_collision;
	return (obj);
}
