#include "verbs.h"

void	revr(t_stack *stack)
{
	int		value;
	t_stack	*tmp_stack;

	tmp_stack = create_stack(stack->top + 1);
	while (stack->top > 0)
		push_stack(tmp_stack, pop_stack(stack));
	value = pop_stack(stack);
	while (tmp_stack->top >= 0)
		push_stack(stack, pop_stack(tmp_stack));
	push_stack(stack, value);
	destroy_stack(tmp_stack);
}

void	revrr(t_stack *stack_a, t_stack *stack_b)
{
	revr(stack_a);
	revr(stack_b);
}