#include "../utils.h"

void	ft_wait(unsigned int miliseconds)
{
	unsigned int	count;
	int				subcount;

	count = 1;
	while (count <= miliseconds)
	{
		subcount = 1;
		while (subcount <= 100)
		{
			usleep(10);
			subcount++;
		}
		count++;
	}
}