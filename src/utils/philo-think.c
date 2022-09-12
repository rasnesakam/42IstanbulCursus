/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo-think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:35:55 by emakas            #+#    #+#             */
/*   Updated: 2022/09/12 15:29:13 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	*philo_think(t_environment *environment)
{
	pthread_mutex_t	*mutex;

	mutex = environment->philosopher->mutex;
	if (get_int_sync(mutex, (int (*)(void *))philo_is_dead,
		(void *)environment->philosopher))
		return (NULL);
	philo_print(*environment, "is thinking");
	return ((void *) environment->philosopher);
}
