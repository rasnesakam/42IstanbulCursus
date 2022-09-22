/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-int-sync.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:50:19 by emakas            #+#    #+#             */
/*   Updated: 2022/09/22 14:35:38 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "concurrency.h"
#include <stdlib.h>

int	get_int_sync(pthread_mutex_t *ref, int (*f)(void *), void *param)
{
	void		*res;
	int			res_int;
	t_function	function;

	function.int_func = f;
	function.arg = param;
	res_int = 0x80000000;
	res = get_synchronized(ref,
			(void *(*)(void *))int_function, (void *)(&function));
	if (res != NULL)
		res_int = *((int *)res);
	free(res);
	return (res_int);
}
