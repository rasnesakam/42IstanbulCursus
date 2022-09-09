/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo-sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:31:40 by emakas            #+#    #+#             */
/*   Updated: 2022/09/08 14:45:07 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	*philo_sleep(t_environment *env)
{
	if (get_int_sync(&(env->philosopher->mutex),
			(int (*)(void *))philo_is_dead, (void *) env->philosopher))
		return (NULL);
	philo_print(*env, "is sleeping");
	usleep(env->sleep_time * 1000);
	return (env->philosopher);
}
