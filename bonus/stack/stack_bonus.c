/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:39:50 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 19:03:57 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_bonus.h"
#include "../utils/utils_bonus.h"
#include <stdio.h>

t_stack	*create_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	stack->datas = (int *) malloc(sizeof(int) * (size));
	if (stack == NULL || stack->datas == NULL)
		return (NULL);
	stack->size = size;
	stack->top = -1;
	return (stack);
}

void	destroy_stack(t_stack *stack)
{
	free(stack->datas);
	free(stack);
}

void	push_stack(t_stack *stack, int value)
{
	if (stack->top < stack->size - 1)
	{
		stack->top += 1;
		stack->datas[stack->top] = value;
	}
	else
		ft_error("STACK OVERFLOW");
}

int	pop_stack(t_stack *stack)
{
	if (stack->top > -1)
	{
		stack->top -= 1;
		return (stack->datas[stack->top + 1]);
	}
	else
		ft_error("STACK IS EMPTY");
	return (0);
}

/**
 * @brief Returns top element of stack
 * Returns top element of stack and keeps it in stack
 * If stack is empty returns INT_MIN (1 << 31)
 */
int	top_stack(t_stack *stack)
{
	if (stack->top > -1)
		return (stack->datas[stack->top]);
	return (1 << 31);
}


void ft_printstack(t_stack stack)
{
	ft_putstr_fd("\nSTACK:", 1);
	ft_putnbr_fd(stack.size, 1);
	ft_putendl_fd("", 1);
	while (stack.top > -1)
		ft_putendl_fd(ft_itoa(pop_stack(&stack)), 1);
	ft_putendl_fd("\n", 1);
}
