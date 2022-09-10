#include "../utils.h"

void	ft_wait(unsigned int miliseconds)
{
	unsigned int	count;
	int				subcount;

	count = 1;
	miliseconds = miliseconds * 2;
	while (count <= miliseconds)
	{
		usleep(50);
		count++;
	}
}