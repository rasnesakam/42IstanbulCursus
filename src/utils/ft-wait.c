#include "../utils.h"

void	ft_wait(unsigned int miliseconds)
{
	unsigned int	count;
	int				subcount;

	count = 1;
	while (count <= miliseconds)
	{
		subcount = 1;
		while (subcount <= 10)
		{
			usleep(100);
			subcount++;
		}
		count++;
	}
}