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
    char *buffer;
    char *s;
    static char *append;
    int ri;

    ri = read(fd,s,BUFFER_SIZE);
    printf("READED: %s\n",s);
    if (ri >= 0)
    {
        while (ri == BUFFER_SIZE && ft_strposi(s,0,'\n') == -1)
        {
            buffer = ft_expand(buffer,s);
            ri = read(fd,s,BUFFER_SIZE);
        }
        printf("READED %d bytes\n",ri);
        printf("BUFFER: %s\n",buffer);
        if (ft_strpos(s,'\n') != NULL && (char *)(ft_strpos(s,'\n') + 1) != NULL)
        {
            append = ft_strpos(s,'\n') + 1;
            printf("APPEND: %s\n",append);
            buffer = ft_substr(buffer,0,ft_strposi(buffer,0,'\n'));
            printf("NEW BUFFER: %s\n",buffer);
        }
        if (ri < BUFFER_SIZE)
        {
            clear_after(&s,ri);
            printf("new S: %s\n",s);
        }

        return (buffer);
    }
    return (NULL);
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

    printf("\nline-5: %s\n", buff);
    buff = get_next_line(fd);

    printf("\nline-6: %s\n", buff);
    buff = get_next_line(fd);

    printf("\nline-7: %s\n", buff);
    buff = get_next_line(fd);

    printf("\nline-8: %s\n", buff);
    buff = get_next_line(fd);
    //printf("line-5: %s", buff);

    /*     while (*(buff = get_next_line(fd)))
    {
        printf("%s",buff);
    } */
    //get_next_line(fd);

    return 0;
}