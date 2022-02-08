#include "get_next_line.h"

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char    *get_next_line(int fd)
{
    static char *buffer;
    char *s;
    static int pos;
    int ri;
    int posendl;

    ri = 1;
    //printf("ENTERING WHILE\n");
    while (ri > 0 && ft_strpos(s,'\n') == NULL)
    {
        //printf("EXPANDING\n");
        ri = read(fd,s,BUFFER_SIZE);
        printf("\nREADED: %s\n",s);
        //printf("EXPANDED STRING: %s\n",ft_expand(buffer,s));
        buffer = ft_expand(buffer,s);
        //printf("EXPANDED\n");
    }
    printf("BUFFER IS: %s",buffer);
    posendl = ft_strposi(buffer,pos,'\n');
    if (posendl >= 0)
    {
        s = ft_substr (buffer, pos, posendl);
        pos = posendl + 1;
    }
    //printf("EXITED IF, CHECKING IF HAS EOF\n");
    else
    {
        s = ft_substr (buffer,pos,ft_strlen(buffer) - 1);
    }
    //printf("BUFFER IS: %s\n",buffer);
    //printf("STRING IS: %s\n",s);
    return (s);
}

int main(void)
{
    int fd;

    fd = open("example.txt",O_CREAT | O_RDWR, 0700);

    if (fd == -1)
        printf("Failed to open...\n");

    char *buff;
    buff = get_next_line(fd);
    printf("\nline-1: %s\n", buff);
    buff = get_next_line(fd);
    printf("\nline-2: %s\n", buff);
    buff = get_next_line(fd);
    printf("\nline-3: %s\n", buff);
    buff = get_next_line(fd);
    printf("\nline-4: %s\n", buff);
    buff = get_next_line(fd);
    //printf("line-5: %s", buff);

    /*     while (*(buff = get_next_line(fd)))
    {
        printf("%s",buff);
    } */
    //get_next_line(fd);

    return 0;
}