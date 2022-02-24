/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:03:07 by emakas            #+#    #+#             */
/*   Updated: 2022/02/24 19:07:19 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int	printed;
	int	last;

	printed = 0;
	if (num < 0)
		printed += ft_putchar('-');
	if (num <= -10)
		printed += ft_putnbr (num / -10);
	if (num >= 10)
		printed += ft_putnbr (num / 10);
	last = num % 10;
	if (last < 0)
		last *= -1;
	printed += ft_putchar('0' + last);
	return (printed);
}
