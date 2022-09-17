/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo-sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:31:40 by emakas            #+#    #+#             */
/*   Updated: 2022/09/17 09:17:20 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	*philo_sleep(t_environment *env)
{
	philo_print(*env, "is sleeping");
	ft_wait(env->sleep_time);
	return (env->philosopher);
}
