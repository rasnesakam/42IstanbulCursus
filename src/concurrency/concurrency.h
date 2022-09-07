/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concurrency.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:47:11 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 15:59:07 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONCURRENCY_H
# define CONCURRENCY_H
# include <pthread.h>

struct		s_function
{
	int		(*int_func)(void *);
	void	*arg;
};

typedef struct s_function	t_function;

int		*int_function(t_function function);

void	call_synchronized(pthread_mutex_t *ref,
			void (*f)(void *), void *param);

void	*get_synchronized(pthread_mutex_t *ref,
			void *(*f)(void *), void *param);

int		get_int_sync(pthread_mutex_t *ref,
			int (*f)(void *), void *param);

#endif