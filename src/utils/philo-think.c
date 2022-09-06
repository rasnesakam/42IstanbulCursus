
#include "../utils.h"

void *philo_think(t_environment *environment)
{
	pthread_mutex_t *mutex;

	mutex = &(environment->philosopher->mutex);
	if (get_int_sync(mutex, (int (*)(void *))philo_is_dead, (void *)environment->philosopher))
	{
		philo_print(*(environment->philosopher), "is thinking");
		return ((void *) environment->philosopher);
	}
	return (NULL);
}