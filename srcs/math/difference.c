#include "vector.h"

static t_list	*elem_rm_s(t_list *head, t_list *to_rm)
{
	t_list		*ret;

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

static int		cmp_range(void *a, void *b)
{
	t_range		s_a;
	t_range		s_b;

	s_a = *((t_range*)a);
	s_b = *((t_range*)b);
	if (s_a.t1.t == s_b.t1.t && s_a.t2.t == s_b.t2.t)
		return (1);
	return (0);
}

static t_list	*split_range(t_list **ret, t_range a, t_range b, t_range *n)
{
	n->t2 = b.t1;
	ft_lstadd(ret, ft_lstnew(n, sizeof(t_range)));
	n->t1 = b.t2;
	ft_lstadd(ret, ft_lstnew(n, sizeof(t_range)));
	*ret = elem_rm_s(*ret, ptr_of(*ret, &a, &cmp_range));
	return (*ret);
}

static t_list	*difference(t_list **ret, t_range a, t_range b)
{
	t_range		n;

	set_spaces_diff(&a, &b);
	n.t1 = a.t1;
	n.t2 = a.t2;
	if (betwx(b.t1.t, a.t1.t, a.t2.t) && betwx(b.t2.t, a.t1.t, a.t2.t))
		return (split_range(ret, a, b, &n));
	else if (betwx(b.t1.t, a.t1.t, a.t2.t) && !betwx(b.t2.t, a.t1.t, a.t2.t))
	{
		n.t2 = b.t1;
		ft_lstadd(ret, ft_lstnew(&n, sizeof(t_range)));
		return (*ret = elem_rm_s(*ret, ptr_of(*ret, &a, &cmp_range)));
	}
	else if (!betwx(b.t1.t, a.t1.t, a.t2.t) && betwx(b.t2.t, a.t1.t, a.t2.t))
	{
		n.t1 = b.t2;
		ft_lstadd(ret, ft_lstnew(&n, sizeof(t_range)));
		return (*ret = elem_rm_s(*ret, ptr_of(*ret, &a, &cmp_range)));
	}
	else if (!betwx(b.t1.t, a.t1.t, a.t2.t) && !betwx(b.t2.t, a.t1.t, a.t2.t))
		if (b.t1.t < a.t1.t && b.t2.t > a.t2.t)
			return (*ret = elem_rm_s(*ret, ptr_of(*ret, &a, &cmp_range)));
	return (0);
}

t_list			*f_d(t_list *a, t_list *b)
{
	t_list		*ret;
	t_list		*tmp_ret;

	ret = NULL;
	while (a)
	{
		ft_lstadd(&ret, ft_lstnew(a->content, sizeof(t_range)));
		a = a->next;
	}
	while (b)
	{
		tmp_ret = ret;
		while (tmp_ret)
		{
			if (!difference(&ret,
					*((t_range*)(tmp_ret->content)),
					*((t_range*)(b->content))))
				tmp_ret = tmp_ret->next;
			else
				tmp_ret = ret;
		}
		b = b->next;
	}
	return (ret);
}
