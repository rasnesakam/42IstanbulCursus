/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:20:25 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 02:20:54 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_analyzer.h"

/**
 * @brief Get the maximum number in stack
 *
 * Returns maximum number in stack.
 * If can't find number (in case of empty stack) it returns
 * '0xFFFFFFFF >> 1' which is maximum integer number represented by definition
 *
 * @param stack
 * @return int
 */
int	get_max(t_stack stack)
{
	int	max;
	int	tmp;

	max = 1 << 31;
	if (stack.top > 0)
		max = pop_stack(&stack);
	while (stack.top >= 0)
	{
		tmp = pop_stack(&stack);
		if (tmp > max)
			max = tmp;
	}
	return (max);
}
