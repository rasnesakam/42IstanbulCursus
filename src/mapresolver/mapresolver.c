#include "mapresolver.h"

void	resolve_map(mlx_vars mlx, char *maddr)
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