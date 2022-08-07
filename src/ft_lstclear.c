/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:26:33 by emakas            #+#    #+#             */
/*   Updated: 2022/01/18 15:33:25 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = *lst;
	if (!lst || !*lst || !del)
		return ;
	while (tmp)
	{
		tmp = tmp->next;
		ft_lstdelone (*lst, del);
		*lst = tmp;
	}
}
