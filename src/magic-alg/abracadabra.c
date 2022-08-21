/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abracadabra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:22:43 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 02:24:58 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack/stack.h"
#include "../data-analyzer/data_analyzer.h"
#include "../verbs/verbs.h"
#include "magic_alg.h"
#include <libft.h>

/**
 * transfer if less than
 */
static void	ft_tiflt(t_stack *stack_a, int filter, t_stack *stack_b)
{
	int	count;
	int	limit;

	count = 0;
	limit = stack_a->top;
	while (count++ <= limit)
	{
		if (top_stack(stack_a) <= filter)
		{
			ft_putendl_fd("pb", 1);
			push(stack_a, stack_b);
		}
		else
		{
			ft_putendl_fd("ra", 1);
			rotate(stack_a);
		}
	}
}

static void	ft_filter(t_stack *stack_a, t_stack *stack_b)
{
	int	avg;

	while (stack_a->top >= 2)
	{
		avg = get_avg(*stack_a);
		ft_tiflt(stack_a, avg, stack_b);
	}
}

static void	ft_short_divide(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top > 2)
	{
		push(stack_a, stack_b);
		ft_putendl_fd("pb", 1);
	}
	ft_sort_rotate(stack_a);
}

void	ft_fit_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	pos_a;
	int	pos_b;

	while (stack_b->top > -1)
	{
		ft_calc_pos(*stack_a, *stack_b, &pos_a, &pos_b);
		ft_rotate_stacks(stack_a, pos_a, stack_b, pos_b);
		push(stack_b, stack_a);
		ft_putendl_fd("pa", 1);
	}
}

void	abracadabra(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;
	int	min;

	if (stack_a->size > 5)
		ft_filter(stack_a, stack_b);
	else
		ft_short_divide(stack_a, stack_b);
	ft_fit_stack(stack_a, stack_b);
	min = get_min(*stack_a);
	pos = find_pos(*stack_a, min, NULL);
	ft_rotpos(stack_a, pos, "a");
	return ;
}
