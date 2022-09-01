#ifndef UTILS_H
# define UTILS_H
# include "philosopher.h"
# include "environment.h"
# include "arg-converter/arg_converter.h"
# include "arg-parser/arg_parser.h"
# include "arg-verifier/arg_verifier.h"
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

/**
 * @brief Tries to take forks.
 * 			if phiosopher dies during take the forks, returns NULL
 * 
 * @param environment Container of philosopher and it's forks and other util datas
 * @return void* NULL if philosopher dies while taking forks. 
 * 			Else, returns address of philosopher
 */
void	*take_forks(t_environment *environment);

/**
 * @brief Tries to eat. If fails, (Maybe, because of death) returns NULL
 *
 * @param environment Environment that contains philosopher, and their forks
 */
void	*philo_eat(t_environment *environment);

/**
 * @brief Tries to sleep. If fails in case of death, returns null
 * 
 * @param environment 
 * @return void* Null if philosopher dies. Else, address of philosopher
 */
void	*philo_sleep(t_environment *environment);

/**
 * @brief Create several (size of args[0]) environment objects
 * 
 * @param arg_count size of argument list
 * @param args Arguments that will be pass in objects
 * @param forks Forks that will be attached
 * @return t_environment* list of t_environment with size args[0]
 */
t_environment   *create_environments(int arg_count, int *args, int *forks);

/**
 * @brief Destroys current environment objects
 * 
 * @param environments that will be destroyed
 * @return 1 if destroys successfully
 */
int	        destroy_environments(t_environment *environments);

/**
 * @brief Create a fork list with 'count' size
 * 
 * @param count size of the list
 * @return int* fork list with size 'count'
 */
int	            *create_forks(int count);

/**
 * @brief Destroys fork list
 * 
 * @param forks list to be destroy
 * @return 1 if destroys succesfully
 */
int             destroy_forks(int *forks);

/**
 * @brief Get the timestamp from given offset.
 * 			if offset is zero, result will be current time with milisecond
 * 
 * @param offset Time that will be exclude to determine passed time from offset
 * @return unsigned long long 
 */
unsigned long long  get_timestamp(unsigned long long offset);




int ft_max(int integer1, int integer2);

char **ft_split(const char *s, char c);

char *ft_strtrim(const char *s1, const char *set);

char *ft_strchr(const char *s, int c);

int	ft_strncmp(const char *s1, const char *s2, size_t n);

size_t ft_strlen(const char *s);

int	ft_isdigit(int c);

size_t ft_strlcpy(char *dest, char *src, size_t dstsize);

#endif