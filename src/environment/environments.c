/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:04:18 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 16:12:59 by emakas           ###   ########.fr       */
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

// TODO: destroy environment data
int	destroy_environments(t_environment *environments)
{
	if (environments != NULL)
	{
		(void) environments;
	}
	return (1);
}
