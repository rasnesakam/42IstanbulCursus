/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:27:17 by emakas            #+#    #+#             */
/*   Updated: 2022/01/12 19:07:03 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char	*ns;
	int		i;

	ns = malloc(sizeof(char));
	i = 0;
	while (*s != '\0')
	{
		ns[i] = (*f)(i,*s++);
		i++;
	}
	return (ns);
}
