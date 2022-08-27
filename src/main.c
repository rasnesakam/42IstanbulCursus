
#include "utils.h"

static void	simulate(void *env)
{
	void	*ret;
	t_environment *environment = (t_environment *) env;

	while (!environment->philosopher->is_died)
	{
		ret = take_forks(environment);
		if (ret == NULL)
			break;
		ret = eat(environment);
		if (ret == NULL)
			break;
		ret = sleep(environment);
		if (ret == NULL)
			break;
	}

}

static void halt_immediate()
{}

// NUM_OF_PHILOS TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP NUMBER_OF_EAT_TIME(OPT)
int main(int ac, char **av)
{
	char			**args;
	int				*int_args;
	int				count_arguments;
	t_philo			*philos;
	t_environment	*envs;

	count_arguments = count_args(ac, av);
	args = collect_args(ac, av);
	if (verify_args(count_arguments, args) && count_arguments > 4)
	{
		int_args = convert_args(count_arguments, args);
		philos = malloc(sizeof(t_philo) * int_args[0]);
		envs = malloc(sizeof(t_environment) * int_args[0]);
		
	}

	// check threads are died. learn more about pthread_detach

	return (0);
}