#include "verbs.h"
#include <libft.h>
#include "../utils/utils.h"

void	rotate(t_stack *stack)
{
	int		value;
	t_stack	*tmp_stack;

	if (stack->top <= 0)
		return ;
	value = pop_stack(stack);
	tmp_stack = create_stack(stack->top + 1);
	if (!tmp_stack)
		ft_error("COULDN'T CREATED TEMPORARY STACK");
	while (stack->top >= 0)
		push_stack(tmp_stack, pop_stack(stack));
	push_stack(stack, value);
	while (tmp_stack->top >= 0)
		push_stack(stack, pop_stack(tmp_stack));
	destroy_stack(tmp_stack);
}

void	rrotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}