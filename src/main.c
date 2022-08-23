
#include "utils.h"

static void	simulate(void *env)
{
	t_environment *environment = (t_environment *) env;

	philo_eat();
	philo_sleep();

}

static void halt_immediate()
{}


int main(int ac, char **av)
{
	char	**args;
	int		*int_args;
	int		count_args;

	count_args = count_args(ac, av);
	args = collect_args(ac, av);
	if (verify_args(count_args, args) && count_args > 4)
	{
		int_args = convert_args(count_args, args);

	}

	// check threads are died. learn more about pthread_detach

	return (0);
}