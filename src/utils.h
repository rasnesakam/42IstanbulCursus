#ifndef UTILS_H
# define UTILS_H
# include "philosopher/philosopher.h"
# include "environment/environment.h"
# include "arg-converter/arg_converter.h"
# include "arg-parser/arg_parser.h"
# include "arg-verifier/arg_verifier.h"
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

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