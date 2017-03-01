#include "libft.h"

void	ft_lstjoin(t_list *head, t_list *to_join)
{
	t_list	*tmp;

	tmp = head;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = to_join;
}
