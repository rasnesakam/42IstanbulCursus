#include "data-analyzer.h"

/**
 * @brief Get the minimum number in stack
 *
 * Returns minimum number in stack
 * If can't find number (in case of empty stack) it returns
 * '1 << 31' which is minimum integer number represented by definition
 *
 * @param stack
 * @return int
 */
int	get_min(t_stack *stack)
{
	t_stack	*tmp_stack;
	int		min;
	int		tmp;

	tmp_stack = create_stack(stack->size);
	min = 1 << 31;
	if (stack->top >= 0)
	{
		min = pop_stack(stack);
		push_stack(tmp_stack,min);
	}
	while (stack->top >= 0)
	{
		tmp = pop_stack(stack);
		if (tmp < min)
			min = tmp;
		push_stack(tmp_stack, tmp);
	}
	while (tmp_stack->top >= 0)
		push_stack(stack, pop_stack(tmp_stack));
	destroy_stack(tmp_stack);
	return (min);
}