/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy-global-mutex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:10:46 by emakas            #+#    #+#             */
/*   Updated: 2022/09/22 15:10:52 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	destroy_global_mutex(void)
{
	pthread_mutex_t	*mutex;

	mutex = get_global_mutex();
	pthread_mutex_destroy(mutex);
	free(mutex);
	return (1);
}
