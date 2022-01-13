/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:22:10 by emakas            #+#    #+#             */
/*   Updated: 2022/01/13 14:40:18 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		tmpnum;
	int		decsize;
	int		last;
	char	*num;

	decsize = 0;
	tmpnum = n;
	if (n <= 0)
		decsize++;
	while (tmpnum != 0)
	{
		tmpnum /= 10;
		decsize++;
	}
	tmpnum = n;
	num = malloc (sizeof(char) * decsize);
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
