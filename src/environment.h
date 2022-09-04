#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# include "philosopher.h"
# include <pthread.h>

struct s_environment
{
	t_philosopher	*philosopher;
	int				eat_time;
	int				sleep_time;
	int				die_time;
	int				remained_food;
	pthread_mutex_t	*forks[2];
};
typedef struct s_environment t_environment;

#endif