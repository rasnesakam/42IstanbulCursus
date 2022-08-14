#include "../stack/stack.h"

int	check_sorted(t_stack *stack)
{
	t_stack	*tmp_stack;
	int		check_val;
	int		tmp_val;
	int		retval;

	tmp_stack = create_stack(stack->size);
	retval = 1;
	if (stack->top > 0)
	{
		check_val = pop_stack(stack);
		push_stack(tmp_stack, check_val);
	}
	while (stack->top >= 0)
	{
		tmp_val = pop_stack(stack);
		if (check_val > tmp_val)
			retval = 0;
		check_val = tmp_val;
		push_stack(tmp_stack, check_val);
	}
	while (tmp_stack->top >= 0)
		push_stack(stack, pop_stack(tmp_stack));
	return (retval);
}
