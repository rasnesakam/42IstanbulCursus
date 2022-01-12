#include "libft.h"

char	*ft_itoa(int n)
{
	int	tmpnum;
	int	decsize;
	int	index;
	char	*num;

	decsize = 0;
	index = 0;
	tmpnum = n;
	if (n < 0)
	{
		decsize++;
	}
	while (tmpnum != 0)
	{
		tmpnum /= 10;
		decsize++;
	}
	num = malloc(sizeof(char) * decsize);
	tmpnum = n;
	while (i < decsize)
	{
		num[i] = 
	}
	return (num);
}
