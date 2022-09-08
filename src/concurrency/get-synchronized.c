/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-synchronized.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:49:55 by emakas            #+#    #+#             */
/*   Updated: 2022/09/08 16:36:35 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "concurrency.h"
#include <stdio.h>

void *get_synchronized(pthread_mutex_t *ref, void *(*f)(void *), void *param)
{
	void	*val_return;

	val_return = NULL;
	if (ref)
	{
		pthread_mutex_lock(ref);
		val_return = f(param);
		pthread_mutex_unlock(ref);
	}
	return (val_return);
}
