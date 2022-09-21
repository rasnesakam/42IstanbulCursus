/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:37:02 by emakas            #+#    #+#             */
/*   Updated: 2022/09/21 18:59:14 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "environment/environment.h"
# include "philosopher/philosopher.h"
# include "arg-converter/arg_converter.h"
# include "arg-parser/arg_parser.h"
# include "arg-verifier/arg_verifier.h"
# include "concurrency/concurrency.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void				*prepare_eat(t_environment *environment);

void				*start_eat(t_environment *environment);

void				*philo_sleep(t_environment *environment);

void				*philo_think(t_environment *environment);

int					check_starve(t_environment *environment);

int					is_ejected(t_environment *env);

int 				all_ejected(t_environment *envs, int count);

/**
 * @brief Prints given philosopher's status with timestamp
 * @param env: Environment that philosopher lives
 * @param message: Exact message that will be printed
 */
void				philo_print(t_environment *env, char *message);

/**
 * @brief Get the single mutex object
 * 
 * @return pthread_mutex_t* 
 */
pthread_mutex_t		*get_global_mutex();

int					destroy_global_mutex();

/**
 * @brief Get the timestamp from given offset.
 * 			if offset is zero, result will be current time with milisecond
 * 
 * @param offset Time that will be exclude to determine passed time from offset
 * @return unsigned long long 
 */
unsigned long long	get_timestamp(unsigned long long offset);

/**
 * @brief Waits in miliseconds
 * 
 * @param miliseconds: miliseconds to wait
 *
 */
void				ft_wait(unsigned int miliseconds);

/*
	external functions
*/
int					ft_max(int integer1, int integer2);

char				**ft_split(const char *s, char c);

char				*ft_strtrim(const char *s1, const char *set);

char				*ft_strchr(const char *s, int c);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

size_t				ft_strlen(const char *s);

int					ft_isdigit(int c);

size_t				ft_strlcpy(char *dest, char *src, size_t dstsize);

#endif