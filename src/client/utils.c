#include "client.h"

void    ft_sig(int pid, int signal){
    kill (pid, signal);
    usleep(100);
}

void    ft_sendsig(int pid, unsigned char msg, int depth)
{
    int remain;

    if ((int) msg >= 2 || depth < 8)
        ft_sendsig(pid, (int) msg / 2, depth + 1);
    remain = (int) msg % 2;
    ft_sig(pid, SIGUSR2); // CLOCK
    if (remain == 1)
        ft_sig(pid, SIGUSR1); // DATA
}

void    ft_sendmsg(int pid, char *msg)
{
    int i;

    i = 0;
    while (msg[i] != '\0')
    {
        ft_sendsig (pid, (unsigned char) msg[i],1);
		i++;
    }
	ft_sendsig(pid, 0, 1);
}