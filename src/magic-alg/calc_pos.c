#include "../stack/stack.h"

static int	ft_min(int i1, int i2)
{
	if (i1 < i2)
		return (i1);
	return (i2);
}

static int	get_optimum_rate(int pos_a, int pos_b, int size_a, int size_b, int diff)
{
	return (ft_min(pos_a, size_a - pos_a) + ft_min(pos_b, size_b - pos_b) + diff);
}


int	find_pos(t_stack stack, int number, int *diff)
{
	int	position;
	int	difference;
	int	old_difference;
	int	return_position;

	old_difference = 0xFFFFFFFF >> 1;
	position = 0;
	return_position = -1;
	while (stack.top > -1)
	{
		difference = pop_stack(&stack) - number;
		if (difference >= 0 && difference < old_difference)
		{
			old_difference = difference;
			if (diff)
				*diff = difference;
			return_position = position;
		}
		position++;
	}
	if (return_position < 0)
		return (position);
	return (return_position);
}

/*

pos_a	pos_b
0		3

STACK:
9



STACK:	pa	pb		df	pnt
6		0	0		3 -> 3
5		0	1		4 -> 5
3		0	2		6 -> 8
4		0	3 (1)	5 -> 6
2		0	4 (0)	7 -> 11


*/

void	ft_calc_pos(t_stack stack_a, t_stack stack_b, int *pos_a, int *pos_b)
{
	int	position_a;
	int	position_b;
	int	oldoptimum_rate;
	int	optimum_rate;
	int	diff;

	position_b = 0;
	oldoptimum_rate = 0xFFFFFFFF >> 1;
	diff = 0;
	while (stack_b.top > -1)
	{
		position_a = find_pos(stack_a, pop_stack(&stack_b), &diff);
		optimum_rate = get_optimum_rate(position_a,
			position_b, stack_a.top, stack_b.top, diff);
		if (optimum_rate < oldoptimum_rate)
		{
			oldoptimum_rate = optimum_rate;
			*pos_a = position_a;
			*pos_b = position_b;
		}
		position_b++;
	}
}