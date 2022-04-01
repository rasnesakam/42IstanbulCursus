#include "server.h"

void handle(int signal){
    static int  clock;
    static int  data;
    static int  tdata;
    static int  csize;

    if (signal == SIGUSR1)
        data = 1;
    if (signal == SIGUSR2)
    {
        clock = 1;
        tdata = (tdata << 1) | (data & clock);
        csize++;
        data = 0;
    }
    if (csize == 9)
    {
        ft_putchar_fd(tdata,1);
        tdata = 0;
    }
}