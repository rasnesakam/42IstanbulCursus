#ifndef STRUCTURES_H
#define STRUCTURES_H

struct s_philo
{
	int	id;
	int	l_hand;
	int	r_hand;
	int	died;
};
typedef struct s_philo t_philo;

struct s_environment
{
	t_philo	philo[200];

	int	eat_time;
	int	sleep_time;
	int	die_time;
	int		*forks;
};
typedef struct s_environment t_environment;

#endif