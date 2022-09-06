# include "concurrency.h"

void *get_synchronized(pthread_mutex_t *ref, void *(*f)(void *), void *param)
{
	void *val_return;

	val_return = NULL;
	if (ref)
	{
		pthread_mutex_lock(ref);
		val_return = (*f)(param);
		pthread_mutex_unlock(ref);
	}
	return (val_return);
}

int	get_int_sync(pthread_mutex_t *ref, int (*f)(void *), void *param)
{
	void	*res;

	res = get_synchronized(ref, int_)
}