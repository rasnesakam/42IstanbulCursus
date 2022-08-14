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
int	get_min(t_stack stack)
{
	int		min;
	int		tmp;

	min = 1 << 31;
	if (stack->top >= 0)
		min = pop_stack(stack);
	while (stack->top >= 0)
	{
		tmp = pop_stack(stack);
		if (tmp < min)
			min = tmp;
	}
	return (min);
}