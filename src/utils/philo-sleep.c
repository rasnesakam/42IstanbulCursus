/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo-sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:31:40 by emakas            #+#    #+#             */
/*   Updated: 2022/09/12 15:29:04 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	*philo_sleep(t_environment *env)
{
	if (get_int_sync(env->philosopher->mutex,
			(int (*)(void *))philo_is_dead, (void *) env->philosopher))
		return (NULL);
	philo_print(*env, "is sleeping");
	ft_wait(env->sleep_time);
	return (env->philosopher);
}
