
#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_object t_object;
typedef struct s_mlx t_mlx;

struct s_object
{
	char	otype;
	char	**image_addr;
	int		width;
	int		height;
	int		x;
	int		y;
	int		orientation;
	int		is_collisionable;
    void    (*on_collision)(t_mlx *mlx,struct s_object *self, struct s_object *smasher);
};

struct s_mlx
{
	void		*mlx;
	void		*win;
	t_object	****mmodel;
	int			*mwidth;
	int			*mheight;
	int			object_size;
	t_object	*player;
	int			*state;
};

#endif