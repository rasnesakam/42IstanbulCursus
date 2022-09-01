
#ifndef PHILSOPHER_H
# define PHILSOPHER_H
# include <pthread.h>
struct s_philosopher
{
	int			id;
	int			is_died;
	unsigned long long	last_eat_timestamp;
	pthread_t	thread;
};
typedef struct s_philosopher t_philosopher;

#endif