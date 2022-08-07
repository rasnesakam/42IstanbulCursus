#include "data-analyzer.h"

/**
 * @brief Get the maximum number in stack
 *
 * Returns maximum number in stack.
 * If can't find number (in case of empty stack) it returns
 * '0xFFFFFFFF >> 1' which is maximum integer number represented by definition
 *
 * @param stack
 * @return int
 */
int get_max(t_stack *stack)
{
	t_stack *tmp_stack;
	int max;
	int tmp;

	tmp_stack = create_stack(stack->size);
	max = 0xFFFFFFFF >> 1;
	if (stack->top > 0)
	{
		max = pop_stack(stack);
		push_stack(tmp_stack, max);
	}
	while (stack->top >= 0)
	{
		tmp = pop_stack(stack);
		if (tmp > max)
			max = tmp;
		push_stack(tmp_stack, tmp);
	}
	while (tmp_stack->top >= 0)
		push_stack(stack, pop_stack(tmp_stack));
	destroy_stack(tmp_stack);
	return (max);
}