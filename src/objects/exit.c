#include "objects.h"

t_object	*on_collision(t_mlx *vars, t_object *self, t_object *smasher)
{
	t_object	***model;
	t_object	*target;
	t_object	*source;
	printf("COLLISION OCCURED! (%c)\n",smasher->otype);
	model = *vars->mmodel;
	target = &model[self->y][self->x][1];
	source = &model[smasher->y][smasher->x][1];
	source->x = target->x;
	source->y = target->y;
	*target = *source;
	destroy_object(source);
	if (target->otype == 'P')
	{
		vars->message = "DID YOU COLLECTED ALL OF DATAS?";
		//mlx_destroy_window(vars->mlx,vars->win);
	}
	return (target);
}

t_object	create_exit(int x, int y)
{
	t_object	exit;
	char		**images;

	images = malloc (sizeof(char *));
	images[0] = "./res/objects/exit/exit.xpm";
	exit = create_object(
		x,
		y,
		0,
		images,
		'E'
		);
	exit.on_collision = on_collision;
	return (exit);
}