#include <signal.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int pid = atoi(argv[1]);
    for (int i = 0; i < 5; i++)
        kill(pid,SIGUSR2);
    for (int i = 0; i < 5; i++)
        kill(pid,SIGUSR1);
    
    return(0);
}