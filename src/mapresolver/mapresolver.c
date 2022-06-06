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
	{
		perror("FILE ERROR");
		exit(1);
	}
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
	}
}

void	renderline(t_mlx mlx, int lindex, char *line)
{
	int	index;

	index = 0;
	while(line[index] != NULL)
	{
		renderpoint(mlx, lindex, index, line[index]);
		index++;
	}
}

void	renderpoint(t_mlx mlx, int lindex, int cindex, char code)
{
	t_object *object;

	if (code == '1')
		object = create_wall (mlx,cindex,lindex);
	else if (code == '0')
		object = create_floor (mlx, cindex, lindex);
	else if (code == 'P' || code == 'C' || code == 'E')
	{
		if (code == 'P')
			object = create_player(mlx, cindex, lindex);
		else if (code == 'C')
			object = create_collectible(mlx, cindex, lindex);
		else if (code == 'E')
			object = create_exit(mlx, cindex, lindex);
		put_object (mlx, create_floor (mlx, cindex, lindex));
	}
	else
		ft_exit("Unknown rule for mapping.", EINVAL);

	put_object(mlx,object);
}