
#include "../utils.h"

void *philo_think(t_environment *environment)
{
	pthread_mutex_t *mutex;

	mutex = &(environment->philosopher->mutex);
	if (!*((int *)get_synchronized(mutex,philo_is_dead, environment->philosopher)))
		philo_print(*(environment->philosopher), "is thinking");
}