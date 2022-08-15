#include "../stack/stack.h"

int	check_sorted(t_stack stack)
{
	int		check_val;
	int		tmp_val;
	int		retval;

	retval = 1;
	if (stack.top > 0)
		check_val = pop_stack(&stack);
	while (stack.top >= 0)
	{
		tmp_val = pop_stack(&stack);
		if (check_val > tmp_val)
			retval = 0;
		check_val = tmp_val;
	}
	return (retval);
}
