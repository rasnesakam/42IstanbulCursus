
#include "utils.h"

void	ft_error(char *message)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(message, 1);
	exit(1);
}