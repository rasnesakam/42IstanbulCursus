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
	}
}

void	destroy_environments(t_environment *environments)
{}
