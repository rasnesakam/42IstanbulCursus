/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo-print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:31:22 by emakas            #+#    #+#             */
/*   Updated: 2022/09/10 07:36:24 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	philo_print(t_environment env, char *message, pthread_mutex_t *mutex)
{
	unsigned long long		timestamp;
	t_philosopher			philosopher;
	int						id;

	philosopher = *(env.philosopher);
	id = philosopher.id;
	timestamp = get_timestamp(env.start_time);
	pthread_mutex_lock(mutex);
	printf("%llu %d %s\n", timestamp, id, message);
	pthread_mutex_unlock(mutex);
}
