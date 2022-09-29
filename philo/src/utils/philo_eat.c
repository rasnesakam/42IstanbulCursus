/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:31:16 by emakas            #+#    #+#             */
/*   Updated: 2022/09/29 14:14:13 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static void	update_last_eat(t_environment *env)
{
	unsigned long long	timestamp;
	pthread_mutex_t		*mutex;
	t_philosopher		*philo;

	philo = env->philosopher;
	mutex = philo->mutex;
	timestamp = get_timestamp(0);
	pthread_mutex_lock(mutex);
	philo->last_eat_timestamp = timestamp;
	pthread_mutex_unlock(mutex);
}

static void	*update_remained_food(t_environment *env)
{
	pthread_mutex_t	*mutex;
	int				remained;

	mutex = env->philosopher->mutex;
	pthread_mutex_lock(mutex);
	if (env->remained_food > 0)
		env->remained_food -= 1;
	remained = env->remained_food;
	pthread_mutex_unlock(mutex);
	if (remained == 0)
		return (NULL);
	return ((void *)env->philosopher);
}

void	*prepare_eat(t_environment *env)
{
	void	*res;

	if (get_int_sync(env->philosopher->mutex, (int (*)(void *))philo_is_dead,
		(void *)env->philosopher))
		return (NULL);
	philo_print(env, "has taken a fork");
	if (env->forks[0] == env->forks[1])
	{
		ft_wait(env->die_time);
		philo_print(env, "is died");
		return (NULL);
	}
	res = get_synchronized(env->forks[1], (void *(*)(void *))start_eat,
			(void *)env);
	return (res);
}

void	*start_eat(t_environment *env)
{
	if (get_int_sync(env->philosopher->mutex, (int (*)(void *))philo_is_dead,
		(void *)env->philosopher))
		return (NULL);
	philo_print(env, "has taken a fork");
	philo_print(env, "is eating");
	ft_wait(env->eat_time);
	if (get_int_sync(env->philosopher->mutex, (int (*)(void *))philo_is_dead,
		(void *)env->philosopher))
		return (NULL);
	update_last_eat(env);
	return (update_remained_food(env));
}
