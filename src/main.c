#include "./arg-parser/arg-parser.h"
#include "./arg-verifier/arg-verifier.h"
#include "./arg-converter/arg-converter.h"
#include "./magic-alg/magic-alg.h"
#include "./stack/stack.h"
#include <stdio.h>


void	load_stack(t_stack *stack, int *list, int size)
{
	printf("LOAD STACK\n");
	while (--size >= 0)
		push_stack(stack, list[size]);
}

int	main(int ac, char **av)
{
	char	**args;
	int		count;
	int		*list;
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	args = collect_args(ac,av);
	count = count_args(ac,av);
	if (verify_args(count, args))
	{
		list = convert_args(count, args);
		stack_a = create_stack(count);
		stack_b = create_stack(count);
		load_stack(stack_a, list, count);
		if (check_sorted(stack_a) == 0)
			abracadabra(stack_a, stack_b);
		destroy_stack(stack_a);
		destroy_stack(stack_b);
	}
	return (0);
}