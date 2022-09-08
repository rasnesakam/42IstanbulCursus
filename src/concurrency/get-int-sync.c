/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-int-sync.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:50:19 by emakas            #+#    #+#             */
/*   Updated: 2022/09/08 16:37:13 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "concurrency.h"
#include <stdlib.h>
#include <stdio.h>
int	get_int_sync(pthread_mutex_t *ref, int (*f)(void *), void *param)
{
	void		*res;
	int			res_int;
	t_function	function;

	function.int_func = f;
	function.arg = param;

	res = get_synchronized(ref,
			(void *(*)(void *))int_function, (void *)(&function));
	res_int = *((int *)res);
	free(res);
	return (res_int);
}
