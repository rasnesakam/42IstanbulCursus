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

int openorext(char *maddr)
{
	int fd;
	int cmp;

	fd = open(maddr, O_RDONLY);
	if (fd < 0)
		ft_exit("FILE ERROR:", errno);
	if (ft_strrchr(maddr,'.') == NULL)
		ft_exit("FILE FORMAT NOT SUPPORTED",EINVAL);
	cmp = ft_strncmp(ft_strrchr(maddr,'.'),
			".ber",ft_strlen(maddr) + ft_strlen(".ber"));
	if ( cmp!= 0)
		ft_exit("FILE FORMAT NOT SUPPORTED",EINVAL);
	return (fd);
}

void	check_all_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			ft_exit("MAP SHOULD BE SURROUNDED BY WALLS",EINVAL);
		i++;
	}
}

int	validate_map(char *maddr, int *xsize, int *ysize)
{
	int		fd;
	char	*line;
	char	*tline;

	fd = openorext(maddr);
	line = read_line(fd);
	if (line == NULL)
		return (0);
	*xsize = ft_strlen(line);
	*ysize = 0;
	check_all_wall(line);
	while (line != NULL)
	{
		if (*xsize != (int) ft_strlen(line))
			ft_exit("MAP SHOULD BE RECTANGULAR",EINVAL);
			char a = line[0];
			char b = line[*xsize - 1];
		if (a != '1' ||  b != '1')
			ft_exit("MAP SHOULD BE SURROUNDED BY WALLS",EINVAL);
		line = read_line(fd);
		if (line != NULL)
			tline = line;
		*ysize += 1;
	}
	check_all_wall(tline);
	return (1);
}

t_object	*renderpoint(int lindex, int cindex, char code)
{
	t_object	*objects;

	objects = ft_calloc(sizeof(t_object ), 2);
	
	if (code == '0')
	{
		objects[0] = get_object(code, cindex, lindex);
		objects[1] = create_null();
	}
	else if (code == '1')
	{
		objects[0] = create_null();
		objects[1] = get_object(code, cindex,lindex);
	}
	else
	{
		objects[0] = get_object('0', cindex, lindex);
		objects[1] = get_object(code, cindex, lindex);
	}
	return (objects);
}

t_object	**renderline(int lindex, int size, char *line)
{
	int			index;
	t_object	**objects;

	index = 0;
	objects = malloc(size * sizeof(t_object *));
	while(line[index] != '\0' && index < size)
	{
		objects[index] = renderpoint(lindex, index, line[index]);
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
		omap[ln] = renderline(ln,*mlx.mwidth,line);
		ln++;
	}
	return (omap);
}