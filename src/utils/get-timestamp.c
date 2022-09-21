/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:28:28 by emakas            #+#    #+#             */
/*   Updated: 2022/09/21 19:08:15 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"
#include <sys/time.h>

// TODO: Implement unimplemented function
unsigned long long	get_timestamp(unsigned long long offset)
{
	struct timeval		time_value;

	gettimeofday(&time_value, NULL);
	return ((time_value.tv_sec * 1000 + time_value.tv_usec / 1000) - offset);
}
