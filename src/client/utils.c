#include "client.h"
#include <stdio.h>

void    ft_sig(int pid, int signal){
    kill (pid, signal);
    usleep(100);
}

void    ft_sendsig(int pid, char msg)
{
    int remain;

    if ((int) msg >= 2)
        ft_sendsig(pid, (int) msg / 2);
    remain = (int) msg % 2;
    ft_sig(pid, SIGUSR2);
    if (remain == 1)
        ft_sig(pid, SIGUSR1);
}

void    ft_sendmsg(int pid, char *msg)
{
    int i;

    i = 0;
    while (msg[i] != '\0')
    {
        ft_sendsig (pid, msg[i++]);
    }
    i = 0;
    while (i <= 8)
    {
        ft_sig(pid, SIGUSR2);
        i++;
    }
}