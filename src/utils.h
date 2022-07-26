

#ifndef UTILS_H
# define UTILS_H
# include <mlx.h>
# include "structures.h"
# include "objects/objects.h"
# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

void		put_object(t_mlx *mlx, t_object *object, int x, int y);
void		ft_exit(char *message, int err);
int			render(void* vars);
t_object	get_object(char code, int x, int y);
t_object	*move_object(t_mlx *mlx, t_object *obj, int x, int y);
t_object	**find_objects(t_mlx mlx, char otype);
int			list_size(t_object **list);
void		list_remove(t_object ***reflist, t_object *ref);
t_object	*move_objects(t_mlx *mlx, t_object *target, t_object *source);
#endif