
#include "utils.h"

static void	*simulate(void *env)
{
	//t_environment	*environment = (t_environment *) env;
	(void) env;
	/*
	while (!environment->philosopher->is_died)
	{
		ret = take_forks(environment);
		if (ret == NULL)
			break;
		ret = philo_eat(environment);
		if (ret == NULL)
			break;
		ret = philo_sleep(environment);
		if (ret == NULL)
			break;
	}
	*/
	return(NULL);
}


static void	start_threads(int count, t_environment *envs)
{
	int	index;

	index = 0;
	while (index < count)
	{
		t_environment *environment = &(envs[index]);

		printf("============================\n");
		printf("\tphilo-> %d\n", environment->philosopher->id);
		printf("\tdie-> %d\n", environment->die_time);
		printf("\teat-> %d\n", environment->eat_time);
		printf("\tsleep-> %d\n", environment->sleep_time);
		printf("\teat-> %d\n", environment->eat_time);
		printf("\tleft fork\t-> [%p]\n", environment->forks[0]);
		printf("\tright fork\t-> [%p]\n", environment->forks[1]);
		printf("============================\n");

		pthread_create(&(envs[index].philosopher->thread),NULL,&simulate,&envs[index]);
		index++;
	}
	index = 0;
	while (index < count)
	{
		pthread_join((envs[index].philosopher->thread), NULL);
		index++;
	}
}

// NUM_OF_PHILOS TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP NUMBER_OF_EAT_TIME(OPT)
int main(int ac, char **av)
{
	char			**args;
	int				*int_args;
	int				count_arguments;
	int				*forks;
	t_environment	*envs;

	count_arguments = count_args(ac, av);
	args = collect_args(ac, av);
	printf("%d\n",count_arguments);
	if (verify_args(count_arguments, args) && count_arguments >= 4)
	{
		int_args = convert_args(count_arguments, args);
		forks = create_forks(int_args[0]);
		envs = create_environments(count_arguments, int_args, forks);
		start_threads(int_args[0], envs);

		// check threads are died. learn more about pthread_detach
		
		// destroy all envs and forks after finished
		destroy_forks(forks);
		usleep(10000);
		destroy_environments(envs);
	}
	return (0);
}