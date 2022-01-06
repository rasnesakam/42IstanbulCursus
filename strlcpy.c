/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:09:44 by emakas            #+#    #+#             */
/*   Updated: 2022/01/06 16:09:56 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int len)
{
	unsigned int	ix;

	ix = 0;
	while (ix < len - 1 && src[ix] != '\0')
	{
		dest[ix] = src[ix];
		ix++;
	}
	dest[ix] = '\0';
	return (ix);
}
