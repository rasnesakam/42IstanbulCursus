
#ifndef PHILSOPHER_H
#define PHILSOPHER_H
#include <pthread.h>

struct s_philosopher
{
	int id;
	int is_died;
	unsigned long long last_eat_timestamp;
	pthread_mutex_t mutex;
	pthread_t thread;
};

typedef struct s_philosopher t_philosopher;

t_philosopher *create_philosopher(int id);

int destroy_philosopher(void *philosopher);

int philo_is_dead(void *philosopher);

void set_philo_dead(void *philosopher);

#endif