
#include "arg-parser/arg-parser.h"
#include "arg-verifier/arg-verifier.h"
#include "arg-converter/arg-converter.h"
#include "stack/stack.h"

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

	t_stack *stack = create_stack(count);
	ft_putstr_fd("stack created with size: ", 1);
	ft_putendl_fd(ft_itoa(count), 1);
	for (int i = 0; i < count; i++)
	{
		push_stack(stack,list[i]);
	}
	ft_putendl_fd("items pushed to stack", 1);
	for (int i = 0; i < count; i++)
	{
		int item = pop_stack(stack);
		ft_putnbr_fd(item,1);
		ft_putendl_fd("",1);
	}
	destroy_stack(stack);
	return (0);
}