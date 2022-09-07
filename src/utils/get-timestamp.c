/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:28:28 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 17:42:10 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"
#include <sys/time.h>

// TODO: Implement unimplemented function
unsigned long long	get_timestamp(unsigned long long offset)
{
	struct timeval		time_value;
	struct timezone		time_zone;
	unsigned long long	timestamp;

	gettimeofday(&time_value, &time_zone);
	timestamp = time_value.tv_sec * 1000 + time_value.tv_usec / 1000;
	return (timestamp - offset);
}
