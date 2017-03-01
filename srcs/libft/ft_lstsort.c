#include "libft.h"

//du plus petit au plus grand
void	ft_lstsort(t_list *lst, int	(*cmp)(void *a, void *b))
{
	t_list		*cur1;
	t_list		*cur2;
	void		*tmp;

	tmp = NULL;
	cur1 = lst;
	while (cur1)
	{
		cur2 = cur1->next;
		while (cur2)
		{
			if (cmp(cur1->content, cur2->content) != 1)
			{
				tmp = cur1->content;
				cur1->content = cur2->content;
				cur2->content = tmp;
			}
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
}
