
#include "arg-converter.h"

int	*convert_args(int ac, char **av)
{
	int	*list;
	int	index;

	if (ac > 0)
	{
		list = malloc(sizeof(int) * ac);
		index = 0;
		while (index < ac)
		{
			list[index] = ft_atoi(av[index]);
			index++;
		}
		return (list);
	}
	return (NULL);
}