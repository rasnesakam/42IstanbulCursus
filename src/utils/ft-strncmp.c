#include "../utils.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 != '\0' || *s2 != '\0') && n--)
	{
		if ((unsigned char)*s1 < (unsigned char)*s2)
			return (-1);
		else if ((unsigned char)*s1 > (unsigned char)*s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}