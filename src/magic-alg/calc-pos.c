/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc-pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:25:07 by emakas            #+#    #+#             */
/*   Updated: 2022/08/29 18:29:53 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magic_alg.h"

static int	get_optimum_rate(int pos_a, int pos_b, int diff)
{
	return ((pos_a + pos_b) * 10 + diff);
}

static int	get_pos_after_max(t_stack stack, int number, int *diff)
{
	int	max;
	int	pos;

	max = get_max(stack);
	pos = find_pos(stack, max, diff);
	*diff = number - max;
	return (pos + 1);
}


static int	get_pos(t_stack stack, int number, int *diff)
{
	int position;
	int difference;
	int old_difference;
	int return_position;

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
	return (return_position);
}
int	find_pos(t_stack stack, int number, int *diff)
{
	int	position;
	
	position = get_pos(stack, number, diff);
	if (position < 0)
		return (get_pos_after_max(stack, number, diff));
	return (position);
}

void	ft_calc_pos(t_stack stack_a, t_stack stack_b, int *pos_a, int *pos_b)
{
	int	position_a;
	int	position_b;
	int	size_b;
	int	optimum_rate;
	int	diff;

	position_b = 0;
	optimum_rate = 0xFFFFFFFF >> 1;
	diff = 0;
	size_b = stack_b.top;
	while (stack_b.top > -1)
	{
		position_a = find_pos(stack_a, pop_stack(&stack_b), &diff);
		if (get_optimum_rate(ft_min(position_a, stack_a.top - position_a),
				ft_min(position_b, size_b - position_b),
				diff) < optimum_rate)
		{
			optimum_rate = get_optimum_rate(ft_min(position_a,
						stack_a.top - position_a), ft_min(position_b,
						size_b - position_b), diff);
			*pos_a = position_a;
			*pos_b = position_b;
		}
		position_b++;
	}
}
