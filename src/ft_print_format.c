/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 02:07:34 by emakas            #+#    #+#             */
/*   Updated: 2022/02/21 15:15:46 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
int	ft_print_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar (va_arg (args, int)));
	else if (format == 's')
		return (ft_putstr (va_arg (args, char *)));
	else if (format == 'p')
		return (ft_putptr (va_arg (args, unsigned long long)));
	else if (format == 'd')
		return (ft_putnbr (va_arg (args, int)));
	else if (format == 'i')
		return (ft_putnbr (va_arg (args, int)));
	else if (format == 'u')
		return (ft_putudecimal (va_arg (args, unsigned int)));
	else if (format == 'x')
		return (ft_puthexlow (va_arg (args, unsigned int)));
	else if (format == 'X')
		return (ft_puthexup ( va_arg (args, unsigned int)));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (0);
}
