#include "../utils.h"

int	destroy_global_mutex()
{
	pthread_mutex_t	*mutex;

	mutex = get_global_mutex();
	pthread_mutex_destroy(mutex);
	free(mutex);
	return (1);
}
