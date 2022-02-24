/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putudecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:03:16 by emakas            #+#    #+#             */
/*   Updated: 2022/02/24 19:08:39 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putudecimal(unsigned int num)
{
	int	printed;

	printed = 0;
	if (num >= 10)
		printed += ft_putudecimal (num / 10);
	printed += ft_putchar ('0' + (num % 10));
	return (printed);
}
