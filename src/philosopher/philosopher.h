
#ifndef PHILSOPHER_H
# define PHILSOPHER_H
# include "utils.h"

typedef struct s_philosopher t_philosopher;
struct s_philosopher
{
	int			id;
	int			is_died;
	unsigned long long	last_eat_timestamp;
	pthread_mutex_t mutex;
	pthread_t	thread;
};

t_philosopher	*create_philosopher(int id);

int	destroy_philosopher(t_philosopher *philosopher);

void	*prepare_eat(t_environment *environment);

void	*start_eat(t_environment *environment);

void	*philo_sleep(t_environment *environment);


#endif