/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:03:19 by emakas            #+#    #+#             */
/*   Updated: 2022/09/22 14:30:20 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# include "../philosopher/philosopher.h"
# include <pthread.h>

struct					s_environment
{
	t_philosopher		*philosopher;
	int					eat_time;
	int					sleep_time;
	int					die_time;
	int					remained_food;
	int					ejected;
	pthread_mutex_t		*forks[2];
	unsigned long long	start_time;
};

typedef struct s_environment	t_environment;

/**
 * @brief Create several (size of args[0]) environment objects
 * 
 * @param arg_count size of argument list
 * @param args Arguments that will be pass in objects
 * @param forks Forks that will be attached
 * @return t_environment* list of t_environment with size args[0]
 */
t_environment	*create_environments(int arg_count,
					int *args, pthread_mutex_t *forks);

/**
 * @brief Destroys current environment objects
 * 
 * @param environments that will be destroyed
 * @param count: Count of environments in list
 * @return 1 if destroys successfully
 */
int				destroy_environments(t_environment *environments, int count);

/**
 * @brief Create a fork list with 'count' size
 * 
 * @param count size of the list
 * @return int* fork list with size 'count'
 */
pthread_mutex_t	*create_forks(int count);

/**
 * @brief Destroys fork list
 * 
 * @param forks list to be destroy
 * @return 1 if destroys succesfully
 */
int				destroy_forks(pthread_mutex_t *forks, int count);

void			eject_env(t_environment *env);

int				get_remained_food(t_environment *env);

#endif