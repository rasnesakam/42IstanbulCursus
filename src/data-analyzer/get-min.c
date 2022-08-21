/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:20:27 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 02:20:34 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_analyzer.h"

/**
 * @brief Get the minimum number in stack
 *
 * Returns minimum number in stack
 * If can't find number (in case of empty stack) it returns
 * '1 << 31' which is minimum integer number represented by definition
 *
 * @param stack
 * @return int
 */
int	get_min(t_stack stack)
{
	int		min;
	int		tmp;

	min = 0xFFFFFFFF >> 1;
	if (stack.top >= 0)
		min = pop_stack(&stack);
	while (stack.top >= 0)
	{
		tmp = pop_stack(&stack);
		if (tmp < min)
			min = tmp;
	}
	return (min);
}
