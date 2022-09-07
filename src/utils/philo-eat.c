/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo-eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:31:16 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 18:02:29 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	*prepare_eat(t_environment *env)
{
	void			*result;
	pthread_mutex_t	*mutex;

	mutex = env->forks[0];
	result = get_synchronized(mutex,
		(void *(*)(void *))start_eat, (void *)env);
	return (result);
}

void	*start_eat(t_environment *env)
{
	pthread_mutex_t	*mutex;
	t_philosopher	*philo;

	mutex = &(env->philosopher->mutex);
	philo = env->philosopher;
	if (get_int_sync(mutex, (int (*)(void *))philo_is_dead, (void *) philo))
		return (NULL);
	philo_print()
	return ((void *)philo);
}
