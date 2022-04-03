#include "server.h"
#include <stdio.h>

void handle(int signal)
{
	static int	csize;
	static int	tdata;

	if (signal == SIGUSR1)
		tdata = tdata | 1;
	if (csize == 8){
		if (tdata == 0)
			ft_putendl_fd("",1);
		ft_putchar_fd(tdata,1);
		csize = 0;
		tdata = 0;
	}
	if (signal == SIGUSR2)
	{
		tdata = tdata << 1;
		csize++;
	}
}