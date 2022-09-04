#ifndef CONCURRENCY_H
# define CONCURRENCY_H
# include <pthread.h>

void call_synchronized(pthread_mutex_t *ref, void (*f)(void *), void *param);

void *get_synchronized(pthread_mutex_t *ref, void *(*f)(void *), void *param);

#endif