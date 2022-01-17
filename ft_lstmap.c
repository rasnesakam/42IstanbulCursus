#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *first;
	t_list *last;

	if (!lst || !f || !del)
		return (NULL);
	first = ft_lstnew(f(lst->content));
	while (lst)
	{
		
		lst = lst->next;
	}
}
