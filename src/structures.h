
#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_object
{
	void	*img;
	char	**image_addr;
	int		width;
	int		height;
	int		x;
	int		y;
	int		orientation;
    void    (*collision)(struct s_object ob1, struct s_object ob2);
}
t_object;

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