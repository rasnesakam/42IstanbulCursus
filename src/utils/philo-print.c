/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo-print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:31:22 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 16:35:13 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	philo_print(t_philosopher philosopher, char *message)
{
	unsigned long long	timestamp;
	int					id;

	timestamp = get_timestamp(0);
	id = philosopher.id;
	printf("%llu %d %s\n", timestamp, id, message);
}
