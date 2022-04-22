
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

typedef struct wall
{}
wall;

typedef struct enemmy
{

}
enemmy;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}
t_vars;

#endif