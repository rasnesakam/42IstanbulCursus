/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo-eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:31:16 by emakas            #+#    #+#             */
/*   Updated: 2022/09/17 08:26:39 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static void update_last_eat(t_environment *env)
{
	unsigned long long timestamp;
	pthread_mutex_t *mutex;
	t_philosopher *philo;
	t_bifunction bifunction;

	philo = env->philosopher;
	mutex = philo->mutex;
	timestamp = get_timestamp(env->start_time);
	bifunction.bifunc = (void (*)(void *, void *))set_philo_last_eat;
	bifunction.arg_1 = (void *)philo;
	bifunction.arg_2 = (void *)&timestamp;
	call_synchronized(mutex,
		(void (*)(void *))call_bifunction, (void *)(&bifunction));
}

static void update_remained_food(t_environment *env)
{
	pthread_mutex_t *mutex;

	mutex = env->philosopher->mutex;
	pthread_mutex_lock(mutex);
	if (env->remained_food > 0)
		env->remained_food -= 1;
	pthread_mutex_unlock(mutex);
}

void	*prepare_eat(t_environment *env)
{
	pthread_mutex_t	*mutex;
	t_philosopher	*philo;
	void			*result;

	mutex = env->forks[1];
	philo = env->philosopher;
	if (get_int_sync(env->philosopher->mutex,
			(int (*)(void *))philo_is_dead, (void *)env->philosopher))
		return (NULL);
	philo_print(*env, "is taken a fork");
	result = get_synchronized(mutex,
			(void *(*)(void *))start_eat, (void *)env);
	return (result);
}

void	*start_eat(t_environment *env)
{
	pthread_mutex_t		*mutex;
	t_philosopher		*philo;

	philo = env->philosopher;
	mutex = philo->mutex;
	philo_print(*env, "is taken a fork");
	philo_print(*env, "is eating");
	ft_wait((env->eat_time));
	if (get_int_sync(mutex, (int (*)(void *))philo_is_dead, (void *) philo))
		return (NULL);
	update_remained_food(env);
	update_last_eat(env);
	return ((void *)philo);
}
