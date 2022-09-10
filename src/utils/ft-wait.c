#include "../utils.h"

void	ft_wait(unsigned int miliseconds)
{
	unsigned int	count;
	int				subcount;

	count = 1;
	miliseconds = miliseconds;
	while (count <= miliseconds)
	{
		usleep(100);
		count++;
	}
}