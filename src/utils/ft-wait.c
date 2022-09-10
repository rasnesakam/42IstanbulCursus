#include "../utils.h"

void	ft_wait(unsigned int miliseconds)
{
	
	unsigned long long	start;

	start = get_timestamp(0);
	while (get_timestamp(start) < miliseconds)
		usleep(1);
}
}