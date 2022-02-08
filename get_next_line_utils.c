#include "get_next_line.h"
#include <stdio.h>

char    *ft_strpos(char *s, int c)
{
    if (s == NULL)
        return (NULL);
    while (*s != '\0')
        if (*s++ == (char) c)
            return (--s);
    if (*s == (char) c)
        return s;
    return (NULL);
}

char    *ft_expand(char *s1, char *s2)
{
    char    *newBuffer;
    int     pos;
    //printf("s1: %s\n",s1);
    //printf("s2: %s\n",s2);
    newBuffer = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    //printf("CREATED STRING WITH SIZE %lu (s1: %d, s2: %d)\n",sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1), ft_strlen(s1), ft_strlen(s2));
    if (newBuffer == NULL)
        return NULL;
    pos = 0;
    //printf("COPYING EXISTING STRING\n");
    while (s1 != NULL && *s1 != '\0')
    {
        //printf("POSITION: %d\n",pos);
        *(newBuffer + pos++) = *(s1++);
    }
    //printf("COPYYING NEW STRING\n");
    while (s2 != NULL && *s2 !=  '\0')
        *(newBuffer + pos++) = *(s2++);
    //printf("ADDING TERMINATOR\n");
    *(newBuffer + pos) = '\0';    
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

int ft_strlen(char *s)
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

    printf("START IS: %d\n",start);
    printf("END IS: %d\n",end);
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