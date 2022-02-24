/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:03:13 by emakas            #+#    #+#             */
/*   Updated: 2022/02/24 19:08:53 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	printed;

	printed = 0;
	if (s == NULL)
		printed += ft_putstr("(null)");
	while (s != NULL && s[printed] != '\0')
		printed += ft_putchar(s[printed]);
	return (printed);
}
