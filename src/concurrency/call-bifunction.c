/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call-bifunction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:21:33 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 18:26:06 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "concurrency.h"

void	call_bifunction(t_bifunction function)
{
	function.bifunction(function.arg_1, function.arg_2);
}