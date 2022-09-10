#include "../utils.h"

void	ft_wait(unsigned int miliseconds)
{
	unsigned int	count;
	int				subcount;

	count = 1;
	while (count <= miliseconds)
	{
		usleep(1);
		count++;
	}
}