/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_global_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:14:32 by emakas            #+#    #+#             */
/*   Updated: 2022/09/22 15:17:27 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

pthread_mutex_t	*get_global_mutex(void)
{
	static pthread_mutex_t	*mutex;

	if (mutex == NULL)
	{
		mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(mutex, NULL);
	}
	return (mutex);
}
