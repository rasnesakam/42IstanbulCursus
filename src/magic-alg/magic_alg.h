/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_alg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:22:28 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 04:32:17 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAGIC_ALG_H
# define MAGIC_ALG_H
# include "../stack/stack.h"
# include "../utils/utils.h"
# include "../data-analyzer/data_analyzer.h"

void	abracadabra(t_stack *stack_a, t_stack *stack_b);
void	ft_calc_pos(t_stack stack_a, t_stack stack_b, int *pos_a, int *pos_b);
int		check_sorted(t_stack stack);
int		find_pos(t_stack stack, int number, int *diff);
void	ft_rotpos(t_stack *stack, int pos, char *stack_name);
void	ft_sort_rotate(t_stack *stack);
void	ft_rotate_stacks(t_stack *stack_a,
			int pos_a, t_stack *stack_b, int pos_b);
#endif