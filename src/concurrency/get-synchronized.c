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
	t_function function;

	function.int_func = f;
	function.arg_1 = param;
	res = get_synchronized(ref, (void *(*)(void *)int_function), function);
}
