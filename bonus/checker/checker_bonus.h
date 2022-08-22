/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:16:54 by emakas            #+#    #+#             */
/*   Updated: 2022/08/22 16:31:40 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "../arg-parser/arg_parser_bonus.h"
# include "../arg-verifier/arg_verifier_bonus.h"
# include "../arg-converter/arg_converter_bonus.h"
# include "../stack/stack_bonus.h"
# include "../verbs/verbs_bonus.h"
# include <get_next_line.h>

void	start_checker(t_stack *stack_a, t_stack *stack_b);

#endif