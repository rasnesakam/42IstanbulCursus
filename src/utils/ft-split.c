
#include "../utils.h"

static unsigned int ft_count(const char *s, char c)
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

static char *ft_create(char *lptr, char *crsr)
{
	char *substr;

	substr = malloc(sizeof(char) * (crsr - lptr + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, lptr, (crsr - lptr + 1));
	return (substr);
}

static void ft_iterate(const char **s, char **lptr, char c)
{
	while (**s && **s == c)
	{
		*s = *s + 1;
		*lptr = (char *)*s;
	}
	while (**s && (**s != c && **s != '\0'))
		*s = *s + 1;
}

char **ft_split(const char *s, char c)
{
	char **arr;
	char *lastptr;
	unsigned int cursor;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!arr)
		return (NULL);
	cursor = 0;
	lastptr = (char *)s;
	while (*s)
	{
		ft_iterate(&s, &lastptr, c);
		if (lastptr < s)
		{
			arr[cursor] = ft_create(lastptr, (char *)s);
			cursor++;
			lastptr = (char *)s;
		}
	}
	arr[cursor] = 0;
	return (arr);
}