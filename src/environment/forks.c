#include "../utils.h"

pthread_mutex_t	*create_forks(int count)
{
	pthread_mutex_t	*forks;
	int	index;

	index = 0;
	forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * count);
	while (index < count)
	{
		pthread_mutex_init(&(forks[index]), NULL);
		index++;
	}
	return (forks);
}

int    destroy_forks(pthread_mutex_t *forks, int count)
{
	int	index;

	index = 0;
	if (forks != NULL)
	{
		while (index < count)
			pthread_mutex_destroy(&(forks[index++]));
		free(forks);
	}
	return (1);
}
