/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:22:10 by emakas            #+#    #+#             */
/*   Updated: 2022/01/19 18:20:10 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_decsize(int n)
{
	int	decsize;

	decsize = 0;
	if (n <= 0)
		decsize++;
	while (n != 0)
	{
		n /= 10;
		decsize++;
	}
	return (decsize);
}

char	*ft_itoa(int n)
{
	int		tmpnum;
	int		decsize;
	int		last;
	char	*num;

	decsize = ft_decsize(n);
	tmpnum = n;
	num = malloc (sizeof(char) * decsize + 1);
	if (!num)
		return (NULL);
	num[decsize] = '\0';
	while (decsize-- > 0)
	{
		last = tmpnum % 10;
		tmpnum /= 10;
		if (last < 0)
			last *= -1;
		num[decsize] = '0' + last;
		if (decsize == 0 && n < 0)
			num[decsize] = '-';
	}
	return (num);
}
