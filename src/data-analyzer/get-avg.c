#include "data-analyzer.h"

/**
 * @brief Get the average number in stack
 *
 * Returns average number in stack.
 * If can't find number (in case of empty stack) it returns
 * '1 << 31' which is minimum integer number represented by definition
 *
 * @param stack
 * @return int
 */
int get_avg(t_stack *stack)
{
	t_stack *tmp_stack;
	int		avg;
	int		count;
	int		tmp;

	avg = 0;
	count = 0;
	if (stack->top < 0)
		return (1 << 31);
	tmp_stack = create_stack(stack->size);
	while (stack->top >= 0)
	{
		tmp = pop_stack(stack);
		avg += tmp;
		count++;
		push_stack(tmp_stack, tmp);
	}
	while (tmp_stack->top >= 0)
		push_stack(stack, pop_stack(tmp_stack));
	destroy_stack(tmp_stack);
	return (avg / count);
}