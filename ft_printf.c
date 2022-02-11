/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 00:02:59 by emakas            #+#    #+#             */
/*   Updated: 2022/02/11 02:14:21 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
"Hello %s"
int	ft_printf(const char *pattern, ...)
{
	va_list	args;
	int		printed;

	va_start (args, pattern);
	while (*pattern != '\0')
	{
		if (*pattern == '%')
		{
			pattern++;
			printed = ft_print_format(*pattern, args);
		}
		else
		{
			ft_putchar(pattern);
			printed++;
		}
		pattern++;
	}
	va_end(args);
}
