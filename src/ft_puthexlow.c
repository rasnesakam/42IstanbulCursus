/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:02:51 by emakas            #+#    #+#             */
/*   Updated: 2022/02/24 19:06:40 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexlow(unsigned int num)
{
	int	printed;

	printed = 0;
	if (num >= 16)
		printed += ft_puthexlow (num / 16);
	ft_putchar ("0123456789abcdef"[num % 16]);
	printed++;
	return (printed);
}
