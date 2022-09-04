#include "philosopher.h"

t_philosopher	create_philosopher(int id)
{
	t_philosopher *philosopher;

	philosopher = (t_philosopher *) malloc(sizeof(t_philosopher));
	if (!philosopher)
		return (NULL);
	philosopher->id = index;
	philosopher->is_died = 0;
	pthread_mutex_init(&(philosopher->mutex));
	return (philosopher);
}