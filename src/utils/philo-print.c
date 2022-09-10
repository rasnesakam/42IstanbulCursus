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

void	philo_print(t_environment env, char *message)
{
	unsigned long long	timestamp;
	t_philosopher		philosopher;
	int					id;
	static pthread_mutex_t		*mutex;

	if (mutex == NULL)
	{
		mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(mutex, NULL);
	}

	philosopher = *(env.philosopher);
	id = philosopher.id;
	pthread_mutex_lock(mutex);
	timestamp = get_timestamp(env.start_time);
	printf("%llu %d %s\n", timestamp, id, message);
	pthread_mutex_unlock(mutex);
}
