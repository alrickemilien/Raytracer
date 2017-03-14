#include "libft.h"

t_list	*ft_lstcpy(t_list *lst)
{
	t_list	*cpy;

	cpy = NULL;
	while (lst)
	{
		ft_lstadd(&cpy, ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
	}
	return (cpy);
}
