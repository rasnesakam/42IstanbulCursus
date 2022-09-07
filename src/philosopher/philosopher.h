/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:16:43 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 17:59:23 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>

struct					s_philosopher
{
	int					id;
	int					is_died;
	unsigned long long	last_eat_timestamp;
	pthread_mutex_t		mutex;
	pthread_t			thread;
};

typedef struct s_philosopher	t_philosopher;

t_philosopher	*create_philosopher(int id);

int				destroy_philosopher(t_philosopher *philosopher);

/**
 * @brief Determines the philosopher is died or not
 * @param philosopher philosopher
 * @return "1" if philosopher died, else zero
 */
int				philo_is_dead(t_philosopher *philosopher);

/**
 * @brief Indicates the philosopher that he/she is died (Sets is_died attribute as "1")
 * @param philosopher to be indicated
 */
void			set_philo_dead(t_philosopher *philosopher);

#endif