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
    char c;
    int pos;
    int ri;

    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (buffer == NULL)
        return (NULL);
    pos = 0;
    ri = read(fd,&c,1);
    if (ri > 0)
        *(buffer + pos++) = c;
    while (pos < BUFFER_SIZE && ri > 0 && c != '\n')
    {
        ri = read(fd,&c,1);
        *(buffer + pos++) = c;
    }
    
    return buffer;
}

int main(void)
{
    int fd;

    fd = open("example.txt",O_CREAT | O_RDWR, 0700);

    if (fd == -1)
        printf("Failed to open...\n");

    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));

    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));

    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));

    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    //get_next_line(fd);

    return 0;
}