/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all-ejected.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:27:30 by emakas            #+#    #+#             */
/*   Updated: 2022/09/16 18:18:19 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static int is_ejected(t_environment *env)
{
	return (env->ejected);
}

int all_ejected(t_environment *envs, int count)
{
	int	index;
	int	res;
	pthread_mutex_t	*mutex;

	index = 0;
	while (index < count)
	{
		mutex = envs[index].philosopher->mutex;
		res = get_int_sync(mutex,(int (*)(void *))is_ejected,
				(void *)(envs + index));
		if (res == 0)
			index--;
		index++;
	}
	return (1);
}