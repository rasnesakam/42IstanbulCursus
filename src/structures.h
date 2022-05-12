
#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_object
{
	void	*img;
	char	*image_addr[2];
	int		width;
	int		height;
	int		x;
	int		y;
	int		orientation;
}
t_object;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}
t_mlx;

#endif