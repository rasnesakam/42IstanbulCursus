#ifndef UTILS_H
# define UTILS_H
# include "philosopher/philosopher.h"
# include "environment/environment.h"
# include "arg-converter/arg_converter.h"
# include "arg-parser/arg_parser.h"
# include "arg-verifier/arg_verifier.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

/**
 * @brief Tries to take forks.
 * 			if phiosopher dies during take the forks, returns NULL
 * 
 * @param environment 
 * @return void* NULL if philosopher dies while taking forks. 
 * 			Else, returns address of philosopher
 */
void	*take_forks(t_environment *environment);
void	*eat(t_environment *environment);
void	*sleep(t_environment *environment);

int ft_max(int integer1, int integer2);

char **ft_split(const char *s, char c);
char *ft_strtrim(const char *s1, const char *set);
char *ft_strchr(const char *s, int c);

#endif