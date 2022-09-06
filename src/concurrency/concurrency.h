#ifndef CONCURRENCY_H
# define CONCURRENCY_H
# include <pthread.h>

int *int_function(int (*f)(void *), void *param);

void	*bi_function(void (*f)(void *, void *), void *param1, void *param2);

void call_synchronized(pthread_mutex_t *ref, void (*f)(void *), void *param);

void *get_synchronized(pthread_mutex_t *ref, void *(*f)(void *), void *param);

int get_int_sync(pthread_mutex_t *ref, int (*f)(void *), void *param);

#endif