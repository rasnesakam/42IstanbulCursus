
#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_object
{
	char	otype;
	char	**image_addr;
	int		width;
	int		height;
	int		x;
	int		y;
	int		orientation;
    void    (*collision)(struct s_object *self, struct s_object *obj);
}
t_object;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_object ****mmodel;
	int		*mwidth;
	int		*mheight;
	int		object_size;
}
t_mlx;

#endif