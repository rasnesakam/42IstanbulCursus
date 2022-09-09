#include "../utils.h"

void	ft_wait(unsigned int miliseconds)
{
	unsigned int	count;

	count = 1;
	while (count <= miliseconds)
	{
		usleep(1000);
		count++;
	}
}