# include "concurrency.h"
void call_synchronized(pthread_mutex_t *ref, void *(*f)(void *), void *param)
{
	if (ref)
	{
		pthread_mutex_lock(ref);
		(*f)(param);
		pthread_mutex_unlock(ref);
	}
}
