#include "../utils.h"

t_environment	*create_environments(int arg_count, int *args, int *forks)
{
	int				index;
	t_environment	*environments;
	t_philosopher	*philosopher;

	environments = malloc(sizeof(t_environment) * args[0]);
	index = 0;
	while (index < arg_count)
	{
		philosopher = malloc(sizeof(t_philosopher));
		philosopher->id = index;
		philosopher->is_died = 0;
		environments[index].die_time = args[1];
		environments[index].eat_time = args[2];
		environments[index].sleep_time = args[3];
		environments[index].philosopher = philosopher;
		environments[index].forks[0] = &(forks[index]);
		environments[index].forks[1] = &(forks[(index + 1) % args[0]]);
	}
	return (environments);
}

void	destroy_environments(t_environment *environments)
{}
