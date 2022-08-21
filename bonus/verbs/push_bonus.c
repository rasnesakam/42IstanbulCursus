/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:35:45 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 18:47:10 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verbs_bonus.h"

void	push(t_stack *stack_from, t_stack *stack_to)
{
	int	value;

	value = pop_stack(stack_from);
	push_stack(stack_to, value);
}
