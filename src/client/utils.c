#include "client.h"

void    ft_sendsig(int pid, char msg)
{
    int remain;

    if ((int) msg >= 2)
        ft_sendsig(pid, (int) msg / 2);
    remain = (int) msg % 2;
    kill (pid, SIGUSR2); // CLOCK SIGNAL
    usleep(100);
    if (remain == 1)
        kill (pid, SIGUSR1); // DATA SIGNAL
    usleep(100);
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
    while (i < 8)
    {
        ft_sendmsg(pid, 0);
        i++;
    }
}