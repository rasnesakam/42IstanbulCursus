/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:35:54 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 05:05:48 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verbs.h"

void	swap(t_stack *stack)
{
	int	val1;
	int	val2;

	val1 = pop_stack(stack);
	val2 = pop_stack(stack);
	push_stack(stack, val1);
	push_stack(stack, val2);
}

void	sswap(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
