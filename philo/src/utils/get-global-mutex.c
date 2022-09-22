#include "../utils.h"

pthread_mutex_t	*get_global_mutex()
{
	static pthread_mutex_t	*mutex;

	if (mutex == NULL)
	{
		mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(mutex, NULL);
	}
	return (mutex);
}