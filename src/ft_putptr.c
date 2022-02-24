/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:03:10 by emakas            #+#    #+#             */
/*   Updated: 2022/02/24 19:07:53 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putull(unsigned long long num)
{
	int	printed;

	printed = 0;
	if (num >= 16)
		printed += ft_putull(num / 16);
	printed += ft_putchar("0123456789abcdef"[num % 16]);
	return (printed);
}

int	ft_putptr(unsigned long long addr)
{
	int	printed;

	printed = ft_putstr ("0x");
	printed += ft_putull (addr);
	return (printed);
}
