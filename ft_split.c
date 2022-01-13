#include "libft.h"

unsigned int	ft_count(const char *s, char c)
{
	unsigned int count;

	count = 0;
	while (*s != '\0')
		if (*s++ == c)
			count++;
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	char	*substr;
	char	*lastptr;
	unsigned int	cursor;

	arr = malloc(sizeof(char*) * (ft_count(s,c) + 1));
	lastptr = (char*) s;
	cursor = 0;
	while (*s++ != '\0')
	{
		if (*s == c || *s == '\0')
		{
			substr = malloc(sizeof(char) * (s - lastptr));
			ft_memcpy(substr,lastptr,(s - lastptr));
			arr[cursor++] = substr;
			lastptr = (char*) ++s;
		}
	}
	return (arr);
}
