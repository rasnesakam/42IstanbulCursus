#include "signalhandler.h"

int main()
{
    int pid = getpid();
    printf("%d\n",pid);
    signal(SIGUSR1,handle);
    signal(SIGUSR2,handle);
    while(1);
    return (0);
}