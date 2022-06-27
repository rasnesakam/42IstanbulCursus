

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

void		put_object(t_mlx *mlx, t_object *object);
void		ft_exit(char *message, int err);
int			render(void* vars);
t_object	get_object(t_mlx mlx, char code, int x, int y);
void		move_object(t_object obj, int x, int y);

#endif