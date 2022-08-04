
#include "arg-parser/arg-parser.h"
#include "arg-verifier/arg-verifier.h"

int	main(int ac, char **av)
{
	char **args = collect_args(ac,av);
	int count = count_args(ac,av);
	
	if (verify_args(count, args))
		ft_putendl_fd("CORRECT!",1);
	else
		ft_putendl_fd("INCORRECT",1);
	
	return (0);
}