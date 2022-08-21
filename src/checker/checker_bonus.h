/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:16:54 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 13:34:47 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../arg-parser/arg_parser.h"
# include "../arg-verifier/arg_verifier.h"
# include "../arg-converter/arg_converter.h"
# include "../stack/stack.h"
# include <get_next_line.h>
void	start_checker(t_stack *stack_a, t_stack *stack_b);
#endif;