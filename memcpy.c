/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:31:59 by emakas            #+#    #+#             */
/*   Updated: 2022/01/05 20:32:02 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, void *src, unsigned int n)
{
	char	*cdst;
	char	*csrc;
	int		cnt;

	cdst = dst;
	csrc = src;
	cnt = 0;
	while (cnt < n)
	{
		cdst[cnt] = csrc[cnt];
		cnt++;
	}
	return (dst);
}
