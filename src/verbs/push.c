/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:35:45 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 05:04:50 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verbs.h"

void	push(t_stack *stack_from, t_stack *stack_to)
{
	int	value;

	value = pop_stack(stack_from);
	push_stack(stack_to, value);
}
