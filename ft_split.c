#include "libft.h"

static unsigned int	ft_count(const char *s, char c)
{
	unsigned int count;
	unsigned int i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else 
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void ft_setfree(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	char	*substr;
	char	*lastptr;
	unsigned int	cursor;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char*) * (ft_count(s,c) + 1 ));
	if (!arr)
		return (NULL);
	cursor = 0;
	while (*s && *s != c)
		s++;
	lastptr = (char *) s;
	while (*s)
	{
		if (*s == c || *s == '\0')
		{
			substr = malloc(sizeof(char) * (s - lastptr + 1));
			if (!substr)
			{
				ft_setfree(arr);
				return (NULL);
			}
			ft_strlcpy(substr, lastptr, (s - lastptr + 1));
			arr[cursor++] = substr;
			//free(substr);
			lastptr = (char *) (s + 1);
		}
		s++;
	}
	arr[cursor] = NULL;
	return (arr);
}
