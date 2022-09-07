/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int-function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:50:58 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 16:03:07 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "concurrency.h"

int	*int_function(t_function function)
{
	int	*res;

	res = malloc(sizeof(int));
	*res = function.int_func(function.arg);
	return (res);
}
