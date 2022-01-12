/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:39:27 by emakas            #+#    #+#             */
/*   Updated: 2022/01/12 19:40:11 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*bptr;
	char	*eptr;
	char	*trimmed;

	bptr = s1;
	while (ft_strchr(set,*bptr) != NULL && *bptr != '\0')
		bptr = ++s1;
	while (*s1 != '\0')
		s1++;
	eptr = s1;
	while (ft_strrchr(set,*eptr) != NULL && eptr != bptr)
		eptr = --s1;
	trimmed = malloc(sizeof(char) * ((eptr - bptr) + 1));
	ft_strlcpy (trimmed, bptr, (eptr - bptr) + 1);
	return (trimmed);
}
