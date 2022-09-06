#include "philosopher.h"
#include <stdlib.h>


t_philosopher	*create_philosopher(int id)
{
	t_philosopher *philosopher;

	philosopher = (t_philosopher *) malloc(sizeof(t_philosopher));
	if (!philosopher)
		return (NULL);
	philosopher->id = id;
	philosopher->is_died = 0;
	pthread_mutex_init(&(philosopher->mutex), NULL);
	return (philosopher);
}

int destroy_philosopher(t_philosopher *philosopher)
{
	(void) philosopher;
	return 1;
}

int	philo_is_dead(t_philosopher *philosopher)
{
	t_philosopher *philo;

	philo = (t_philosopher *) philosopher;
	return (philo->is_died);
}

void set_philo_dead(t_philosopher *philosopher)
{
	t_philosopher *philo;

	philo = (t_philosopher *) philosopher;
	philo->is_died = 1;
}
