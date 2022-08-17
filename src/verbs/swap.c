#include "verbs.h"

void	swap(t_stack *stack)
{
	int	val1;
	int	val2;

	val1 = pop_stack(stack);
	val2 = pop_stack(stack);
	push_stack(stack, val1);
	push_stack(stack, val2);
}

void	sswap(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}