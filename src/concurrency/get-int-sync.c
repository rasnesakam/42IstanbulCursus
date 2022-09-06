#include "concurrency.h"

int	get_int_sync(pthread_mutex_t *ref, int (*f)(void *), void *param)
{
	void	*res;
	int		res_int;
	t_function function;

	function.int_func = f;
	function.arg_1 = param;
	res = get_synchronized(ref, (void *(*)(void *)int_function), function);
	res_int = (int *)*res;
	free(res);
	return (res_int);
}
