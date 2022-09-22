/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-synchronized.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:49:55 by emakas            #+#    #+#             */
/*   Updated: 2022/09/16 15:19:53 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "concurrency.h"
#include <stdio.h>

void *get_synchronized(pthread_mutex_t *ref, void *(*f)(void *), void *param)
{
	void	*val_return;
	int		return_mutex;

	val_return = NULL;
	if (ref)
	{
		return_mutex = pthread_mutex_lock(ref);
		if (return_mutex > 0)
			return (NULL);
		val_return = f(param);
		return_mutex = pthread_mutex_unlock(ref);
		if (return_mutex > 0)
			return (NULL);
	}
	return (val_return);
}
