/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:03:05 by emakas            #+#    #+#             */
/*   Updated: 2022/02/24 19:06:50 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexup(unsigned int num)
{
	int	printed;

	printed = 0;
	if (num >= 16)
		printed += ft_puthexup (num / 16);
	ft_putchar ("0123456789ABCDEF"[num % 16]);
	printed++;
	return (printed);
}
