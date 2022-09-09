/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo-print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:31:22 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 18:04:51 by emakas           ###   ########.fr       */
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
		mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));

	philosopher = *(env.philosopher);
	id = philosopher.id;
	timestamp = get_timestamp(env.start_time);
	pthread_mutex_init(mutex, NULL);
	pthread_mutex_lock(mutex);
	printf("[%p]\t%llu %d %s\n",mutex, timestamp, id, message);
	pthread_mutex_unlock(mutex);
	pthread_mutex_destroy(mutex);
}
