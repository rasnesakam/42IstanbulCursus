#include "../utils.h"

static void	set_env(\
t_environment *env, \
t_philosopher *philo, \
int *args, \
pthread_mutex_t *forks)
{
	int	index;

	index = philo->id;
	env->die_time = args[1];
	env->eat_time = args[2];
	env->sleep_time = args[3];
	env->remained_food = -1;
	env->philosopher = philo;
	env->forks[0] = &(forks[index]);
	env->forks[1] = &(forks[(index + 1) % args[0]]);
}

t_environment	*create_environments(\
int arg_count, \
int *args, \
pthread_mutex_t *forks
)
{
	int				index;
	t_environment	*environments;
	t_philosopher	*philosopher;

	environments = (t_environment *) malloc(sizeof(t_environment) * args[0]);
	if (environments == NULL)
		return (NULL);
	index = 0;
	while (index < args[0])
	{
		philosopher = create_philosopher(index);
		if (!philosopher && destroy_environments(environments))
			return (NULL);
		set_env(&(environments[index]), philosopher, args, forks);
		if (arg_count > 4)
			environments[index].remained_food = args[4];
		index++;
	}
	return (environments);
}

int	destroy_environments(t_environment *environments)
{
	if (environments != NULL)
	{
		// TODO: destroy environment data
	}
	return (1);
}
