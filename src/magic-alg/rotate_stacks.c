/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:24:03 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 04:34:17 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack/stack.h"
#include "../verbs/verbs.h"
#include "../data-analyzer/data_analyzer.h"
#include "magic_alg.h"
#include <libft.h>

static void
	ft_rotate_mutual(t_stack *stack_a, int *pos_a, t_stack *stack_b, int *pos_b)
{
	if (*pos_a < (stack_a->top + 1) / 2 && *pos_b < (stack_b->top + 1) / 2)
	{
		while (*pos_a > 0 && *pos_b > 0)
		{
			rrotate(stack_a, stack_b);
			ft_putendl_fd("rr", 1);
			(*pos_a)--;
			(*pos_b)--;
		}
	}
	else if (*pos_a >= (stack_a->top + 1) / 2
		&& *pos_b >= (stack_b->top + 1) / 2)
	{
		while (*pos_a < (stack_a->top + 1) && *pos_b < (stack_b->top + 1))
		{
			revrr(stack_a, stack_b);
			ft_putendl_fd("rrr", 1);
			(*pos_a)++;
			(*pos_b)++;
		}
		if (*pos_a >= (stack_a->top + 1))
			*pos_a -= (stack_a->top + 1);
		if (*pos_b >= (stack_b->top + 1))
			*pos_b -= (stack_b->top + 1);
	}
}

void	ft_rotpos(t_stack *stack, int pos, char *stack_name)
{
	char	*name;

	if (pos > (stack->top / 2))
	{
		pos = stack->top + 1 - pos;
		while (pos-- > 0)
		{
			revr(stack);
			name = ft_strjoin("rr", stack_name);
			ft_putendl_fd(name, 1);
			free(name);
		}
	}
	else
	{
		while (pos-- > 0)
		{
			rotate(stack);
			name = ft_strjoin("r", stack_name);
			ft_putendl_fd(name, 1);
			free(name);
		}
	}
}

void
	ft_rotate_stacks(t_stack *stack_a, int pos_a, t_stack *stack_b, int pos_b)
{
	if (stack_a->top > 0 && stack_b->top > 0)
		ft_rotate_mutual(stack_a, &pos_a, stack_b, &pos_b);
	if (stack_a->top > 0)
		ft_rotpos(stack_a, pos_a, "a");
	if (stack_b->top > 0)
		ft_rotpos(stack_b, pos_b, "b");
}

void	ft_sort_rotate(t_stack *stack)
{
	int	posmax;
	int	posmin;

	posmax = find_pos(*stack, get_max(*stack), NULL);
	posmin = find_pos(*stack, get_min(*stack), NULL);
	if (posmin - posmax == 1)
	{
		if (posmax > 0)
		{
			revr(stack);
			ft_putendl_fd("rra", 1);
		}
		else
		{
			rotate(stack);
			ft_putendl_fd("ra", 1);
		}
	}
	else
	{
		swap(stack);
		ft_putendl_fd("sa", 1);
	}
	if (check_sorted(*stack) == 0)
		ft_sort_rotate(stack);
}
