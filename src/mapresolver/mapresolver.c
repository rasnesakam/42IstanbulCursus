#include "mapresolver.h"
#include <libft.h>
#include <unistd.h>

char	*read_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
		if (line != NULL)
			line = ft_strtrim(line," \t\n");
	return line;
}

int	validate_map(char *maddr, int *xsize, int *ysize)
{
	int		fd;
	int		llen;
	int		h;
	char	*line;

	fd = open(maddr, O_RDONLY);
	if (fd < 0)
		ft_exit("FILE ERROR:", errno);
	line = read_line(fd);
	if (line == NULL)
		return (0);
	llen = ft_strlen(line);
	h = 0;
	while (line != NULL)
	{
		if (llen != (int) ft_strlen(line))
			return (0);
		line = read_line(fd);
		h++;
	}
	*xsize = llen;
	*ysize = h;
	return (1);
}

t_object	*renderpoint(t_mlx mlx, int lindex, int cindex, char code)
{
	t_object	*objects;

	objects = malloc(sizeof(t_object ) * 2);
	
	if (code == '0')
		objects[0] = get_object(mlx, code, cindex, lindex);
	if (code == '1')
		objects[1] = get_object(mlx, code, cindex,lindex);
	else
	{
		objects[0] = get_object(mlx, '0', cindex, lindex);
		objects[1] = get_object(mlx, code, cindex, lindex);
	}
	return (objects);
}

t_object	**renderline(t_mlx mlx, int lindex, int size, char *line)
{
	int			index;
	t_object	**objects;

	index = 0;
	objects = malloc(size * sizeof(t_object *));
	while(line[index] != '\0' && index < size)
	{
		objects[index] = renderpoint(mlx, lindex, index, line[index]);
		index++;
	}
	return (objects);
}

t_object	***create_map_model(t_mlx mlx, char *file)
{
	int			fd;
	int			ln;
	char		*line;
	t_object	***omap;

	fd = open(file, O_RDONLY);
	ln = 0;
	omap = malloc( ((sizeof(t_object) * 2) * *mlx.mwidth) * *mlx.mheight);
	if (omap == NULL)
		return (omap);
	while (ln < *mlx.mheight)
	{
		line = read_line(fd);
		omap[ln] = renderline(mlx, ln,*mlx.mwidth,line);
		ln++;
	}
	return (omap);
}