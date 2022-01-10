#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char *ns;
	int		i;

	ns = malloc(sizeof(char));
	i = 0
	while (*s != '\0')
	{
		ns[i] = (*f)(i,*s++);
		i++;
	}
	return (ns);	
}
