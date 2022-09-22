/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:31:22 by emakas            #+#    #+#             */
/*   Updated: 2022/09/22 15:17:48 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	philo_print(t_environment *env, char *message)
{
	pthread_mutex_t			*mutex;
	int						id;

	id = env->philosopher->id;
	mutex = get_global_mutex();
	pthread_mutex_lock(mutex);
	if (!get_int_sync(env->philosopher->mutex, (int (*)(void *))philo_is_dead,
		(void *)env->philosopher))
		printf("%llu %d %s\n", get_timestamp(env->start_time), id, message);
	pthread_mutex_unlock(mutex);
}
