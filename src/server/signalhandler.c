#include "signalhandler.h"

void handle(int signal){
    static int usr2c;
    static int usr1c;

    if (!usr1c)
        usr1c = 0;
    
    if (!usr2c)
        usr2c = 0;

    if (signal == SIGUSR2)
        printf("SIGUSR2: %d\n",usr2c++);
    if (signal == SIGUSR1)
        printf("SIGUSR1: %d\n",usr1c++);
    
}