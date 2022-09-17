/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:36:52 by emakas            #+#    #+#             */
/*   Updated: 2022/09/17 09:16:27 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	*simulate(void *environment)
{
	t_environment	*env;
	void			*ret;


	env = (t_environment *) environment;

	if (env->start_time == 0)
		env->start_time = get_timestamp(0);
	
	while (1)
	{
		ret = get_synchronized(env->forks[0],
				(void *(*)(void *)) prepare_eat, (void *)env);
		if (ret == NULL)
			break ;
		ret = philo_sleep(env);
		if (ret == NULL)
			break ;
		ret = philo_think(env);
		if (ret == NULL)
			break ;
	}
	call_synchronized(env->philosopher->mutex, 
		(void (*)(void *)) eject_env, environment);
	return (NULL);
}

static void	start_threads(int count, t_environment *envs)
{
	t_environment	*environment;
	int index;
	int ext;

	ext = 0;
	while (ext < 2)
	{
		index = ext;
		while (index < count)
		{
			environment = &(envs[index]);
			pthread_create(&(environment->philosopher->thread),
						   NULL, &simulate, environment);
			pthread_detach(environment->philosopher->thread);
			index += 2;
		}
		usleep(1000);
		ext++;
	}
}

static void	kill_all(t_environment *envs, int count)
{
	int				index;
	pthread_mutex_t	*mutex;

	index = 0;
	while (index < count)
	{
		mutex = envs[index].philosopher->mutex;
		call_synchronized(mutex,
			(void (*)(void *))set_philo_dead,
			(void *)envs[index].philosopher);
		index++;
	}
}

static void	listen_philos(int count, t_environment *envs)
{
	int				index;

	while (1)
	{
		index = 0;
		while (index < count)
		{
			if (check_starve(envs[index]))
			{
				if (check_starve(envs[index]))
					philo_print(envs[index], "is died");
				//pthread_mutex_lock(get_global_mutex());
				kill_all(envs, count);
				return ;
			}
			index++;
		}
		usleep(1);
	}
}

// NUM_OF_PHILOS TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP NUMBER_OF_EAT_TIME(OPT)

int	main(int ac, char **av)
{

	char			**args;
	int				*int_args;
	int				count_arguments;
	pthread_mutex_t	*forks;
	t_environment	*envs;

	count_arguments = count_args(ac, av);
	args = collect_args(ac, av);
	if (verify_args(count_arguments, args) && count_arguments >= 4)
	{
		int_args = convert_args(count_arguments, args);
		forks = create_forks(int_args[0]);
		envs = create_environments(count_arguments, int_args, forks);
		get_global_mutex();
		start_threads(int_args[0], envs);
		listen_philos(int_args[0], envs);
		if (all_ejected(envs, int_args[0]))
		{
			destroy_global_mutex();
			destroy_forks(forks, int_args[0]);
			destroy_environments(envs, int_args[0]);
		}
	}
	return (0);
}
