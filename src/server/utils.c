#include "server.h"

void handle(int signal){
    static int  clock;
    static int  data;
    static int  bsize;

    if (signal == SIGUSR2)
    {
        if (clock == NULL || clock == 0)
            clock = 1;
        else {
            data = (data << 1) | 0;
            bsize++;
        }
    }
    if (signal == SIGUSR1)
    {
        if (data == NULL)
            data = 0;
        data = (data << 1) | 1;
        bsize++;
        clock = 0;
    }

    if (bsize == 8){
        ft_putchar_fd(data,1);
        bsize = 0;
    }
    
}