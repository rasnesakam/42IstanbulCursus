#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	tmp = *lst;
	if (!lst || !*lst || !del)
		return;
	while (tmp)
	{
		tmp = tmp->next;
		ft_lstdelone(*lst,del);
		*lst = tmp;
	}
}
