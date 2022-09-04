#include "../utils.h"

pthread_mutex_t	*create_forks(int count)
{
	pthread_mutex_t	*forks;
	int	index;

	index = 0;
	forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * count);
	while (index < count)
	{
		pthread_mutex_init();
		index++;
	}
	return (forks);
}

int    destroy_forks(pthread_mutex_t *forks)
{
	if (forks != NULL)
		free(forks);
	return (1);
}
