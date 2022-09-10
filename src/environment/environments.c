/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:04:18 by emakas            #+#    #+#             */
/*   Updated: 2022/09/10 07:39:06 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	env->start_time = 0;
	env->philosopher = philo;
	env->forks[0] = &(forks[index - 1]);
	env->forks[1] = &(forks[(index) % args[0]]);
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
		philosopher = create_philosopher(index + 1);
		if (!philosopher && destroy_environments(environments, index + 1))
			return (NULL);
		set_env(&(environments[index]), philosopher, args, forks);
		if (arg_count > 4)
			environments[index].remained_food = args[4];
		index++;
	}
	return (environments);
}

// TODO: destroy environment data
int	destroy_environments(t_environment *environments, int count)
{
	int index;

	if (environments != NULL)
	{
		index = 0;
		while (index < count)
		{
			destroy_philosopher(environments[index].philosopher);
			index++;
		}
		free(environments);
	}
	return (1);
}
