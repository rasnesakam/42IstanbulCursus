#include "../../lib/libft/libft.h"

int main()
{
    int pid = getpid();
    ft_putnbr_fd(pid,1);
    ft_putendl_fd("",1);
    return (0);
}