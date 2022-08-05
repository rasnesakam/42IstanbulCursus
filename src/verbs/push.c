#include "verbs.h"

void	push(t_stack *stack_from, t_stack *stack_to)
{
	int	value;

	value = pop_stack(stack_from);
	push_stack(stack_to, value);
}