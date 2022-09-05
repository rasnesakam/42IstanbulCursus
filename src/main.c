
#include "philosopher/philosopher.h"
#include "environment/environment.h"
#include "arg-converter/arg_converter.h"
#include "arg-parser/arg_parser.h"
#include "arg-verifier/arg_verifier.h"
#include "concurrency/concurrency.h"

static void	*simulate(void *env)
{
	t_environment	*environment;
	t_philosopher	*philo;
	pthread_mutex_t	*mutex;
	void			*ret;
	
	environment = (t_environment *) env;
	while (!(*((int *)get_synchronized(mutex, philo_is_dead, philo))))
	{
		
		ret = get_synchronized(environment->forks[1], prepare_eat, environment);
		if (ret == NULL)
			break;
		ret = philo_sleep(environment);
		if (ret == NULL)
			break;

		ret = philo_think(environment);
		if (ret == NULL)
			break;
		}
	return(NULL);
}


static void	start_threads(int count, t_environment *envs)
{
	int				index;
	t_environment	*environment;

	index = 0;
	while (index < count)
	{
		environment = &(envs[index]);
		pthread_create(&(envs[index].philosopher->thread),NULL,&simulate,&envs[index]);
		pthread_detach(envs[index].philosopher->thread);
		index++;
	}
	index = 0;
	while (index < count)
	{
		pthread_join((envs[index].philosopher->thread), NULL);
		index++;
	}
}

static void	kill_all(t_environment *envs, int count)
{
	int	index;
	pthread_mutex_t *mutex;

	while(index < count)
	{
		mutex = &(envs[index].philosopher->mutex); 
		call_synchronized(mutex, set_philo_dead, envs[index].philosopher);
	}
}

static void listen_philos(int count, t_environment *envs)
{
	int	loop;
	int index;
	pthread_mutex_t *mutex;

	loop = 1;
	while (loop)
	{
		index = 0;
		while (index < count)
			if (get_synchronized(mutex, philo_is_dead, envs[index].philosopher))
			{
				kill_all_(envs, count);
				loop = 0;
			}
		usleep(5000);
	}
}

// NUM_OF_PHILOS TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP NUMBER_OF_EAT_TIME(OPT)
int main(int ac, char **av)
{
	char			**args;
	int				*int_args;
	int				count_arguments;
	pthread_mutex_t	*forks;
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
		listen_philos(int_args[0], envs);
		destroy_forks(forks, int_args[0]);
		destroy_environments(envs);
	}
	return (0);
}