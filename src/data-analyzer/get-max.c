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
int get_max(t_stack stack)
{
	int max;
	int tmp;

	max = 0xFFFFFFFF >> 1;
	if (stack.top > 0)
		max = pop_stack(stack);
	while (stack.top >= 0)
	{
		tmp = pop_stack(stack);
		if (tmp > max)
			max = tmp;
	}
	return (max);
}