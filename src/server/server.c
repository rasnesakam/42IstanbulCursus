#include "server.h"

int main()
{
    int	pid;
	
	pid = getpid();
	ft_putendl_fd(ft_itoa(pid), 1);
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	while (1) ;
    return (0);
}
