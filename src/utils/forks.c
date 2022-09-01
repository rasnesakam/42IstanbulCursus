#include "../utils.h"

int	*create_forks(int count)
{
	int	*forks;
	int	index;

	index = 0;
	forks = (int *) malloc(sizeof(int) * count);
	while (index < count)
	{
		forks[index] = 1;
		index++;
	}
	return (forks);
}

int    destroy_forks(int *forks)
{
	if (forks != NULL)
		free(forks);
	return (1);
}
