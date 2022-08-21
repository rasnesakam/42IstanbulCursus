/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:35:48 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 05:05:12 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verbs.h"
#include <libft.h>
#include "../utils/utils.h"

void	rotate(t_stack *stack)
{
	int		value;
	t_stack	*tmp_stack;

	if (stack->top <= 0)
		return ;
	value = pop_stack(stack);
	tmp_stack = create_stack(stack->size);
	if (!tmp_stack)
		ft_error("COULDN'T CREATED TEMPORARY STACK");
	while (stack->top >= 0)
		push_stack(tmp_stack, pop_stack(stack));
	push_stack(stack, value);
	while (tmp_stack->top >= 0)
		push_stack(stack, pop_stack(tmp_stack));
	destroy_stack(tmp_stack);
}

void	rrotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
