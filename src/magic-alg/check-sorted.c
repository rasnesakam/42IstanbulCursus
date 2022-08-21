/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check-sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:23:05 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 04:23:06 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack/stack.h"

int	check_sorted(t_stack stack)
{
	int		check_val;
	int		tmp_val;
	int		retval;

	retval = 1;
	if (stack.top > 0)
		check_val = pop_stack(&stack);
	while (stack.top >= 0)
	{
		tmp_val = pop_stack(&stack);
		if (check_val > tmp_val)
			retval = 0;
		check_val = tmp_val;
	}
	return (retval);
}
