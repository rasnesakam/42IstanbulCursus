
#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct object
{
	void	*img;
	char	*image_addr;
	int		width;
	int		height;
	int		x;
	int		y;
}
object;

typedef struct mlx_vars
{
	void	*mlx;
	void	*win;
}
mlx_vars;

#endif