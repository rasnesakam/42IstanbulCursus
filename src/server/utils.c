#include "server.h"

void handle(int signal){
    static int  clock;
    static int  data;
    static int  bsize;

    if (signal == SIGUSR2)
        clock = 1;
    if (signal == SIGUSR1)
    {
        
    }

    
}