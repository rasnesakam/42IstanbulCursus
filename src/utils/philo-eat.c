/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo-eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:31:16 by emakas            #+#    #+#             */
/*   Updated: 2022/09/08 18:41:09 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	*prepare_eat(t_environment *env)
{
	pthread_mutex_t	*mutex;
	t_philosopher	*philo;
	void			*result;

	mutex = env->forks[0];
	philo = env->philosopher;
	if (get_int_sync(mutex, (int (*)(void *))philo_is_dead, (void *) philo))
		return (NULL);
	philo_print(*env, "is taken a fork");
	result = get_synchronized(mutex,
			(void *(*)(void *))start_eat, (void *)env);
	return (result);
}

void	*start_eat(t_environment *env)
{
	unsigned long long	timestamp;
	pthread_mutex_t		*mutex;
	t_philosopher		*philo;
	t_bifunction		bifunction;

	mutex = &(env->philosopher->mutex);
	philo = env->philosopher;
	if (get_int_sync(mutex, (int (*)(void *))philo_is_dead, (void *) philo))
		return (NULL);
	philo_print(*env, "is taken a fork");
	philo_print(*env, "is eating");
	usleep((env->eat_time) * 1000);
	if (get_int_sync(mutex, (int (*)(void *))philo_is_dead, (void *) philo))
		return (NULL);
	timestamp = get_timestamp(env->start_time);
	bifunction.bifunc = (void (*)(void *, void *)) set_philo_last_eat;
	bifunction.arg_1 = (void *) philo;
	bifunction.arg_2 = (void *) &timestamp;
	call_synchronized(&(philo->mutex),
		(void (*)(void *))call_bifunction, (void *)(&bifunction));
	return ((void *)philo);
}
