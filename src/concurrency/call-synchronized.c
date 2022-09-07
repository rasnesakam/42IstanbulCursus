/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call-synchronized.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:50:05 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 16:00:26 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "concurrency.h"

void
	call_synchronized(pthread_mutex_t *ref, void *(*f)(void *), void *param)
{
	if (ref)
	{
		pthread_mutex_lock(ref);
		(*f)(param);
		pthread_mutex_unlock(ref);
	}
}
