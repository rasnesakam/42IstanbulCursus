/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:26:16 by emakas            #+#    #+#             */
/*   Updated: 2022/01/20 18:47:39 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*last;
	t_list	*tmp;

	if (!f || !lst)
		return (NULL);
	last = ft_lstnew((*f)(lst->content));
	if (!last)
		return (NULL);
	first = last;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_lstclear (&first, del);
			return (NULL);
		}
		last->next = tmp;
		last = tmp;
		lst = lst->next;
	}
	return (first);
}
