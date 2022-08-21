/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start-checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:28:54 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 11:52:17 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	replicate(char *command, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(command,"rrr",ft_srtlen(command)) == 0)
		revrr(stack_a, stack);
	else if (ft_strncmp(command,"rrb",ft_srtlen(command)) == 0)
		revr(stack_b);
	else if (ft_strncmp(command,"rra",ft_srtlen(command)) == 0)
		revr(stack_a);
	else if (ft_strncmp(command,"rr",ft_srtlen(command)) == 0)
		rrotate(stack_a, stack_b);
	else if (ft_strncmp(command,"rb",ft_srtlen(command)) == 0)
		rotate(stack_b);
	else if (ft_strncmp(command,"ra",ft_srtlen(command)) == 0)
		rotate(stack_a);
	else if (ft_strncmp(command,"pb",ft_srtlen(command)) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(command,"pa",ft_srtlen(command)) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(command,"ss",ft_srtlen(command)) == 0)
		sswap(stack_a, stack);
	else if (ft_strncmp(command,"sb",ft_srtlen(command)) == 0)
		swap(stack_b);
	else if (ft_strncmp(command,"sa",ft_srtlen(command)) == 0)
		swap(stack_a);
}

void	start_checker(t_stack *stack_a, t_stack *stack_b)
{
	int		fd;
	char	*input;

	input = get_next_line(0);
	while (input != NULL)
	{
		replicate(input, stack_a, stack_b);
		input = get_next_line(0);
	}
}