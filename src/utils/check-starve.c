/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check-starve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:08:08 by emakas            #+#    #+#             */
/*   Updated: 2022/09/08 18:29:15 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"
#include <pthread.h>

int	check_starve(t_environment environment)
{
    pthread_mutex_t     mutex;
    t_philosopher       *philosopher;
    unsigned long long  starve_time;
    unsigned long long  die_time;

    philosopher = environment.philosopher;
    mutex = philosopher->mutex;
    die_time = (unsigned long long) environment.die_time;
    pthread_mutex_lock(&mutex);
    starve_time = get_timestamp(environment.start_time)
                     - philosopher->last_eat_timestamp;
    pthread_mutex_unlock(&mutex);

    return (starve_time > die_time);
}