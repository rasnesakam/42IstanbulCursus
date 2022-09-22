/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call-bifunction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:21:33 by emakas            #+#    #+#             */
/*   Updated: 2022/09/22 14:35:10 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "concurrency.h"

void	call_bifunction(t_bifunction *function)
{
	function->bifunc(function->arg_1, function->arg_2);
}
