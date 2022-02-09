#include "get_next_line.h"
#include <stdio.h>

char    *ft_strpos(char *s, int c)
{
    if (s == NULL)
        return (NULL);
    while (*s != '\0')
    {
        if (*s == (char) c)
            return (s);
        s++;
    }
    if (*s == (char) c)
        return s;
    return (NULL);
}

char    *ft_expand(const char *s1, const char *s2)
{
    char    *newBuffer;
    int     pos;

    newBuffer = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (newBuffer == NULL)
        return NULL;
    printf("new buffer\n");
    pos = 0;
    while (s1 != NULL && *s1 != '\0')
    {
        printf("%c",*s1);
        newBuffer[pos] = (char) *s1;
        pos++;
        s1++;
    }
    while (s2 != NULL && *s2 != '\0')
    {
        printf("%c",*s2);
        newBuffer[pos] = (char) *s2;
        pos++;
        s2++;
    }
    newBuffer[pos] = '\0';    
    return newBuffer;
}

int ft_strposi(char *str, int start, int search)
{
    int index;

    index = start;
    if (str == NULL)
        return (-1);
    while (str[index] != '\0')
        if (str[index++] == (char) search)
            return (--index);
    if (str[index] == (char) search)
        return (index);
    return (-1);
}

int ft_strlen(const char *s)
{
    int count;

    count = 0;
    while (s != NULL && *(s++) != '\0')
        count++;
    return (count);
}

char    *ft_substr(char *s, int start, int end)
{
    char    *newstr;
    char    *flag;
    int     pos;

    //printf("START IS: %d\n",start);
    //printf("END IS: %d\n",end);
    pos = start;
    newstr = malloc(sizeof(char) * (end - start + 2));
    if (newstr == NULL)
        return (NULL);
    flag = newstr;
    while (pos <= end)
    {
        *newstr++ = s[pos];
        pos++;
    }
    *newstr = '\0';
    return (flag);
}

void    clear_after(char **s, int after)
{
    while ((*s)[after] != '\0')
    {
        (*s)[after] = '\0';
        after++;
    }
}