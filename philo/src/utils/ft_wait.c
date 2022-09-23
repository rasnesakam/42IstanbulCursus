/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:11:07 by emakas            #+#    #+#             */
/*   Updated: 2022/09/23 14:42:59 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	ft_wait(unsigned int miliseconds)
{
	unsigned long long	start;

	start = get_timestamp(0);
	while (get_timestamp(start) < miliseconds)
		usleep(250);
}
