/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo-print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:31:22 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 18:04:51 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	philo_print(t_environment env, char *message)
{
	unsigned long long	timestamp;
	t_philosopher		philosopher;
	int					id;

	philosopher = *(env.philosopher);
	id = philosopher.id;
	timestamp = get_timestamp(env.start_time);
	printf("%llu %d %s\n", timestamp, id, message);
}
