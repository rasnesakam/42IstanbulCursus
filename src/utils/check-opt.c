#include "../utils.h"

int	check_opt(t_environment env)
{
	int remained;

	pthread_mutex_lock(env.philosopher->mutex);
	remained = env.remained_food;
	pthread_mutex_unlock(env.philosopher->mutex);
	return (remained == 0);
}