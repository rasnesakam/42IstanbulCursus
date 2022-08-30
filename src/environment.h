#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

struct s_environment
{
	t_philosopher	*philosopher;
	int				eat_time;
	int				sleep_time;
	int				die_time;
	int				*forks;
};
typedef struct s_environment t_environment;

#endif