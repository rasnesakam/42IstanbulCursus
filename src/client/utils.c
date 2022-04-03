#include "client.h"
#include <stdio.h>

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
	printf("c");
    if (remain == 1)
        ft_sig(pid, SIGUSR1); // DATA
	printf("%d",remain);
}

void    ft_sendmsg(int pid, char *msg)
{
    int i;

    i = 0;
    while (msg[i] != '\0')
    {
        ft_sendsig (pid, (unsigned char) msg[i],1);
		printf(" (%d)\n", (unsigned char)msg[i]);
		i++;
    }
	ft_sendsig(pid, 0, 1);
	//ft_sig(pid, SIGUSR2);
	printf("c\n");
}