#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int pid = getpid();
    printf("%d\n",pid);
    return (0);
}