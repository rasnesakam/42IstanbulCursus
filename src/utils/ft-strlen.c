#include "../utils.h"

size_t ft_strlen(const char *s)
{
	size_t c;

	c = 0;
	while (*(s++) != '\0')
		c++;
	return (c);
}