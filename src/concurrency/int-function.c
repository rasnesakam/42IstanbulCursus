#include "concurrency.g"

int *int_function(int (*f)(int), param)
{
	int *res;

	res = malloc(sizeof(int));
	*res = f();
	return (res);
}