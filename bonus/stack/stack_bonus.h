/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:39:54 by emakas            #+#    #+#             */
/*   Updated: 2022/08/22 15:38:47 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_BONUS_H
# define STACK_BONUS_H
# include <stdlib.h>

struct	s_stack
{
	int			*datas;
	int			top;
	int			size;
};

typedef struct s_stack	t_stack;

t_stack	*create_stack(int size);
void	destroy_stack(t_stack *stack);
void	push_stack(t_stack *stack, int value);
int		pop_stack(t_stack *stack);
int		top_stack(t_stack *stack);
//void	ft_printstack(t_stack stack);
#endif