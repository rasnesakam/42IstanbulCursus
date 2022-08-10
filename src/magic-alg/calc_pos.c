int	find_pos(t_stack stack, int number)
{
	int	position;
	int	difference;
	int	old_difference;

	old_difference = 0xFFFFFFFF >> 1;
	position = 0;
	while (stack.top > -1)
	{
		difference = pop_stack(&stack) - number;
		if (difference > 0 && difference < old_difference)
		{
			old_difference = difference;
			position++;
		}
	}
	return (position);
}

void	ft_calc_pos(t_stack stack_a, t_stack stack_b, int *pos_a, int *pos_b)
{
	int	position_a;
	int	position_b;
	int	optimum_rate;

	position_b = 0;
	optimum_rate = 0xFFFFFFFF >> 1;
	while (stack_b.top > -1)
	{
		position_a = find_pos(stack_a, pop_stack(&stack_b));
		if (get_optimum_rate(position_a,position_b,stack_a.size, stack_b.size) < optimum_rate)
		position_b++;
	}
}