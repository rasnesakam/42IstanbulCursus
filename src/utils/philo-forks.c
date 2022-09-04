#include "../utils.h"

void *synchronized(pthread_mutex_t *ref, void *(*f)(void *), void *param)
{
	void *val_return;
	val_return = (*f)(param);
	return (val_return);
}


void	*take_forks(t_environment *env)
{
	pthread_mutex_t *fork_right;
	pthread_mutex_t *fork_left;
	t_philosopher *philo;

	philo = env->philosopher;
	fork_right = env->forks[1];
	fork_left = env->forks[0];

	//mutex
	return (NULL);
}

void	*leave_forks(t_environment *env)
{
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	t_philosopher	*philo;

	philo = env->philosopher;
	fork_right = env->forks[1];
	fork_left = env->forks[0];


	return (NULL);
}