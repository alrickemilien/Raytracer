#include "libft.h"

t_list	*ptr_of(t_list *lst, void *data, int (*cmp)(void *a, void *b))
{
	while (lst)
	{
		if (cmp(data, lst->content))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
