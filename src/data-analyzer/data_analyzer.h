/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_analyzer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:19:52 by emakas            #+#    #+#             */
/*   Updated: 2022/08/21 02:21:34 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_ANALYZER_H
# define DATA_ANALYZER_H
# include "../stack/stack.h"

int	get_avg(t_stack stack);
int	get_max(t_stack stack);
int	get_min(t_stack stack);

#endif