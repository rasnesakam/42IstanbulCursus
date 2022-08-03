#include "../libft/libft.h"
#include "arg-parser/arg-parser.h"

int	main(int ac, char **av)
{
	char **args = collect_args(ac,av);
	int i = 0;
	
	while ( i < count_args(ac,av))
	{
		ft_putendl_fd(args[i],1);
		i++;
	}
	
	return (0);
}