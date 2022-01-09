/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:13:24 by emakas            #+#    #+#             */
/*   Updated: 2022/01/09 17:14:16 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	int	last;

	if (num <= -10)
	{
		ft_putchar_fd ('-', fd);
		ft_putnbr_fd (num / -10, fd);
	}
	if (num >= 10)
		ft_putnbr_fd (num / 10, fd);
	last = num % 10;
	if (last < 0)
		last *= -1;
	ft_putchar_fd ('0' + last, fd);
}
