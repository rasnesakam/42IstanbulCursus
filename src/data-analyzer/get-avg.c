/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-avg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:20:19 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 02:21:47 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_analyzer.h"

/**
 * @brief Get the average number in stack
 *
 * Returns average number in stack.
 * If can't find number (in case of empty stack) it returns
 * '1 << 31' which is minimum integer number represented by definition
 *
 * @param stack
 * @return int
 */
int	get_avg(t_stack stack)
{
	long	avg;
	int		count;
	int		tmp;

	avg = 0;
	count = 0;
	if (stack.top < 0)
		return (1 << 31);
	while (stack.top >= 0)
	{
		tmp = pop_stack(&stack);
		avg += tmp;
		count++;
	}
	return (avg / count);
}
