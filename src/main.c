#include "./arg-parser/arg-parser.h"
#include "./arg-verifier/arg-verifier.h"
#include "./arg-converter/arg-converter.h"
#include "./magic-alg/magic-alg.h"
#include "./stack/stack.h"
#include <stdio.h>


void	load_stack(t_stack *stack, int *list, int size)
{
	while (--size >= 0)
	{
		push_stack(stack, list[size]);
		//printf("pushed: %d\n", list[size]);
		//printf("stack b: [%p][%p]\n", stack, stack->datas);
	}
}

int	main(int ac, char **av)
{
	char	**args;
	int		count;
	int		*list;
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	args = collect_args(ac,av);
	count = count_args(ac, av);
	printf("count: %d\n", count);
	stack_a = create_stack(count);
	printf("stack a: [%p][%p]\n", stack_a, stack_a->datas);
	//stack_b = create_stack(count);
	stack_b = create_stack(count);
	printf("stack b: [%p][%p]\n", stack_b, stack_b->datas);
	printf("stack a: [%p][%p]\n", stack_a, stack_a->datas);
	if (verify_args(count, args) && stack_a && stack_b)
	{
		list = convert_args(count, args);
		load_stack(stack_a, list, count);
		printf("stack b: [%p][%p]\n", stack_b, stack_b->datas);
		printf("stack a: [%p][%p]\n", stack_a, stack_a->datas);
		if (check_sorted(*stack_a) == 0)
			abracadabra(stack_a, stack_b);
		destroy_stack(stack_a);
		destroy_stack(stack_b);
	}
	else if (count > 0)
		ft_putendl_fd("Error", 1);
	return (0);
}