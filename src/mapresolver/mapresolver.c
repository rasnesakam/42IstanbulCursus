#include "mapresolver.h"

void	resolve_map(t_mlx mlx, char *maddr)
{
	int fd;
	int ln;
	char *line;

	fd = open(maddr, O_RDONLY);
	ln = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		renderline(mlx,ln,line);
	}
}

int	validate_map(char *maddr, int *xsize, int *ysize)
{
	int		fd;
	int		llen;
	char	*line;

	fd = open(maddr, O_RDONLY);
	if (fd < 0)
		ft_exit("FILE ERROR",errno);
	else
	{
		line = get_next_line(fd);
		*xsize = ft_len(line);
		llen = *xsize;
		*ysize = 0;
		while (llen == *xsize && line != NULL)
		{
			(*ysize)++;
			line = get_next_line(fd);
			llen = ft_len(line);
		}
		if (llen != *xsize)
			return (0);
		return (1);
	}
}

t_object	*renderline(t_mlx mlx, int lindex, int size, char *line)
{
	int			index;
	t_object	**objects;

	index = 0;
	objects = malloc(size * sizeof(t_object));
	while(line[index] != NULL && index < size)
	{
		objects[index] = renderpoint(mlx, lindex, index, line[index]);
		index++;
	}
	return (objects);
}

t_object	*renderpoint(t_mlx mlx, int lindex, int cindex, char code)
{
	t_object	*objects;
	t_object	*object;
	objects = malloc(sizeof(t_object ) * 2);
	if (code == '1')
		object = create_wall (mlx,cindex,lindex);
	else if (code == '0')
		object = create_floor (mlx, cindex, lindex);
	else if (code == 'P')
		object = create_player(mlx, cindex, lindex);
	else if (code == 'C')
		object = create_collectible(mlx, cindex, lindex);
	else if (code == 'E')
		object = create_exit(mlx, cindex, lindex);
	else
		ft_exit("Unknown rule for mapping.", EINVAL);
	if (code == '0')
		objects[0] = *object;
	else
		objects[1] = *object;
	free(object);
	return (object);
}

t_object	***create_map_model(t_mlx mlx, char *file)
{
	int			fd;
	int			ln;
	int			w;
	int			h;
	char		*line;
	t_object	***omap;

	fd = open(file, O_RDONLY);
	ln = 0;
	line = get_next_line(fd);
	if (validate_map(file,&w,&h) > 0)
	{
		omap = malloc( ((sizeof(t_object) * 2) * w) * h);
		while (ln < h)
		{
			omap[ln] = renderline(mlx,ln,w,line);
			line = get_next_line(fd);
			ln++;
		}
	}
}