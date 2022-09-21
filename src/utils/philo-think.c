/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo-think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:35:55 by emakas            #+#    #+#             */
/*   Updated: 2022/09/21 16:11:57 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	*philo_think(t_environment *environment)
{
	if (get_int_sync(environment->philosopher->mutex,
			(int (*)(void *))philo_is_dead,
		(void *)environment->philosopher))
		return (NULL);
	philo_print(environment, "is thinking");
	return ((void *) environment->philosopher);
}
