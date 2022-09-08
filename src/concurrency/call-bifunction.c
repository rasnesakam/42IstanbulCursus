/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call-bifunction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:21:33 by emakas            #+#    #+#             */
/*   Updated: 2022/09/08 16:43:20 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "concurrency.h"

void	call_bifunction(t_bifunction *function)
{
	function->bifunc(function->arg_1, function->arg_2);
}