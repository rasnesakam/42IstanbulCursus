#include "philosopher.h"

struct s_philosopher
{
	int id;
	int is_died;
	unsigned long long last_eat_timestamp;
	pthread_mutex_t mutex;
	pthread_t thread;
};

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

int	philo_is_dead(t_philosopher *philosopher)
{
	return (philosopher->is_died);
}

void set_philo_dead(t_philosopher *philosopher)
{
	philosopher->is_died = 1;
}
