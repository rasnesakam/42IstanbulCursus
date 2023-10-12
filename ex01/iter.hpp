#ifndef ITER_HPP
#define ITER_HPP
#include <cstdlib>

template <typename T>
void iter(T *address, std::size_t len, void (*func)(T))
{
	std::size_t i = 0;
	while(i < len)
	{
		func(address[i]);
		i++;
	}
}

#endif