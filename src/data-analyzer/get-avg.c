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
int get_avg(t_stack stack)
{
	int		avg;
	int		count;
	int		tmp;

	avg = 0;
	count = 0;
	if (stack.top < 0)
		return (1 << 31);
	while (stack.top >= 0)
	{
		tmp = pop_stack(&stack);
		avg += tmp;
		count++;
	}
	return (avg / count);
}