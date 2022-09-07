/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:15:51 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 18:33:29 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>

t_philosopher	*create_philosopher(int id)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *) malloc(sizeof(t_philosopher));
	if (!philosopher)
		return (NULL);
	philosopher->id = id;
	philosopher->is_died = 0;
	pthread_mutex_init(&(philosopher->mutex), NULL);
	return (philosopher);
}

int	destroy_philosopher(t_philosopher *philosopher)
{
	(void) philosopher;
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
