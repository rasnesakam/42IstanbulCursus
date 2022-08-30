
#ifndef PHILSOPHER_H
#define PHILSOPHER_H

struct s_philosopher
{
	int			id;
	int			left_hand;
	int			right_hand;
	int			is_died;
	unsigned long long	last_eat_timestamp;
	pthread_t	thread;
};
typedef struct s_philosopher t_philosopher;

#endif