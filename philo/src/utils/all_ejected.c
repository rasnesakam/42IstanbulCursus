/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all-ejected.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:27:30 by emakas            #+#    #+#             */
/*   Updated: 2022/09/22 15:08:54 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	is_ejected(t_environment *env)
{
	return (env->ejected);
}

int	all_ejected(t_environment *envs, int count)
{
	pthread_mutex_t	*mutex;
	int				index;
	int				res;

	index = 0;
	while (index < count)
	{
		mutex = envs[index].philosopher->mutex;
		res = get_int_sync(mutex, (int (*)(void *))is_ejected,
				(void *)(envs + index));
		if (res == 0)
			index--;
		index++;
	}
	return (1);
}
