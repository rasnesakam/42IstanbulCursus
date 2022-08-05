
#include "arg-parser/arg-parser.h"
#include "arg-verifier/arg-verifier.h"
#include "arg-converter/arg-converter.h"

int	main(int ac, char **av)
{
	char **args = collect_args(ac,av);
	int count = count_args(ac,av);
	
	if (verify_args(count, args))
		ft_putendl_fd("CORRECT!",1);
	else
		ft_putendl_fd("INCORRECT",1);
	
	int *list = convert_args(count, args);
	ft_putendl_fd("list created",1);
	for (int i = 0; i < count; i++)
	{
		ft_putnbr_fd(list[i],1);
		ft_putendl_fd("",1);
	}

	return (0);
}