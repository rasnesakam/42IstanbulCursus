/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start-checker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:28:54 by emakas            #+#    #+#             */
/*   Updated: 2022/08/22 15:46:50 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_eject(char *ptr)
{
	free(ptr);
	ft_error(NULL);
}

static void	replicate(char *command, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(command, "rrr\n", ft_strlen(command)) == 0)
		revrr(stack_a, stack_b);
	else if (ft_strncmp(command, "rrb\n", ft_strlen(command)) == 0)
		revr(stack_b);
	else if (ft_strncmp(command, "rra\n", ft_strlen(command)) == 0)
		revr(stack_a);
	else if (ft_strncmp(command, "rr\n", ft_strlen(command)) == 0)
		rrotate(stack_a, stack_b);
	else if (ft_strncmp(command, "rb\n", ft_strlen(command)) == 0)
		rotate(stack_b);
	else if (ft_strncmp(command, "ra\n", ft_strlen(command)) == 0)
		rotate(stack_a);
	else if (ft_strncmp(command, "pb\n", ft_strlen(command)) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(command, "pa\n", ft_strlen(command)) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(command, "ss\n", ft_strlen(command)) == 0)
		sswap(stack_a, stack_b);
	else if (ft_strncmp(command, "sb\n", ft_strlen(command)) == 0)
		swap(stack_b);
	else if (ft_strncmp(command, "sa\n", ft_strlen(command)) == 0)
		swap(stack_a);
	else
		ft_eject(command);
}

void	start_checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*input;

	input = get_next_line(0);
	while (input != NULL)
	{
		replicate(input, stack_a, stack_b);
		input = get_next_line(0);
	}
}
