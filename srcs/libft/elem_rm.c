#include "libft.h"

t_list	*elem_rm(t_list *head, t_list *to_rm)
{
	t_list	*ret;

	ret = NULL;
	if (!head)
		return (NULL);
	if (head == to_rm)
	{
		ret = head->next;
		free(head->content);
		free(head);
		return (ret);
	}
	head->next = elem_rm(head->next, to_rm);
	return (head);
}
