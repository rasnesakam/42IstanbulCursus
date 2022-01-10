/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:18:06 by emakas            #+#    #+#             */
/*   Updated: 2022/01/10 19:23:21 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char *ns;
	char *fst;

	ns = malloc(sizeof(char) * len);
	fst = ns;
	if (start < ft_strlen(s))
		while (s[start] != '\0' && len-- > 0)
			*ns++ = s[start++];
	*ns = '\0';
	return (fst);
}
