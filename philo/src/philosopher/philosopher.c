/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:15:51 by emakas            #+#    #+#             */
/*   Updated: 2022/09/22 15:06:16 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>
#include <stdio.h>

t_philosopher	*create_philosopher(int id)
{
	t_philosopher	*philosopher;
	pthread_mutex_t	*mutex;

	philosopher = (t_philosopher *) malloc(sizeof(t_philosopher));
	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!philosopher || !mutex)
		return (NULL);
	philosopher->id = id;
	philosopher->is_died = 0;
	pthread_mutex_init(mutex, NULL);
	philosopher->mutex = mutex;
	return (philosopher);
}

int	destroy_philosopher(t_philosopher *philosopher)
{
	if (philosopher)
	{
		pthread_mutex_destroy(philosopher->mutex);
		free(philosopher->mutex);
		free(philosopher);
	}
	return (1);
}

int	philo_is_dead(t_philosopher *philosopher)
{
	return (philosopher->is_died);
}

void	set_philo_dead(t_philosopher *philosopher)
{
	philosopher->is_died = 1;
}

void	set_philo_last_eat(t_philosopher *philo,
			unsigned long long *last_eat_timestamp)
{
	philo->last_eat_timestamp = *last_eat_timestamp;
}
