/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:27:47 by emakas            #+#    #+#             */
/*   Updated: 2022/09/07 16:35:25 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*bptr;
	char	*eptr;
	char	*trimmed;

	bptr = (char *)s1;
	while (ft_strchr(set, *bptr) != NULL && *bptr != '\0')
		bptr = (char *)++s1;
	while (*s1 != '\0')
		s1++;
	eptr = (char *)s1;
	while (ft_strchr(set, *eptr) != NULL && eptr != bptr)
	{
		eptr = (char *)--s1;
	}
	trimmed = malloc(sizeof(char) * ((eptr - bptr + 1) + 1));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, bptr, (eptr - bptr + 1) + 1);
	return (trimmed);
}
