
#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_object
{
	void	*img;
	char	*image_addr;
	int		width;
	int		height;
	int		x;
	int		y;
}
t_object;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}
t_mlx;

#endif