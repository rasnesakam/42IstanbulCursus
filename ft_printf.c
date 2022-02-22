/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 00:02:59 by emakas            #+#    #+#             */
/*   Updated: 2022/02/22 19:33:43 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *pattern, ...)
{
	va_list	args;
	int		printed;

	printed = 0;
	va_start (args, pattern);
	while (*pattern != '\0')
	{
		if (*pattern == '%')
		{
			pattern++;
			printed += ft_print_format(*pattern, args);
		}
		else
		{
			printed += ft_putchar(*pattern);
		}
		pattern++;
	}
	va_end(args);
	return (printed);
}

int main(void)
{
	ft_printf("%x\n",540);
	return (0);
}