/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc-pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:25:07 by emakas            #+#    #+#             */
/*   Updated: 2022/08/29 15:47:15 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magic_alg.h"

static int	get_optimum_rate(int pos_a, int pos_b, int diff)
{
	return ((pos_a + pos_b)  + diff);
}
#include <stdio.h>
/*
static int	after_last(t_stack stack, int number, int *diff)
{
	int	max;
	int	pos;

	ft_printstack(stack);

	max = get_max(stack);
	//printf("max: %d\n", max);
	pos = find_pos(stack, max, diff);
	//printf("pos: %d\n", pos);
	*diff = number - max;
	return (pos);
}
*/
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
