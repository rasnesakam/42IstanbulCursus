
#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "objects/objects.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_object ***mmodel;
	int		mwidth;
	int		mheigth;
}
t_mlx;

#endif