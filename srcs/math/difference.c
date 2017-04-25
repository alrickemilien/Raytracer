#include "vector.h"
#include <stdio.h>

static void	set_spaces_diff(t_range *a, t_range *b)
{
	if (a->t1.t > a->t2.t)
		swap(&a->t1.t, &a->t2.t);
	if (b->t1.t > b->t2.t)
		swap(&b->t1.t, &b->t2.t);
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

static void split_range(t_list **ret, t_range a, t_range b, t_range *n)
{
	n->t2 = b.t1;
	ft_lstadd(ret, ft_lstnew(n, sizeof(t_range)));
	n->t1 = b.t2;
	ft_lstadd(ret, ft_lstnew(n, sizeof(t_range)));
	*ret = elem_rm(*ret, ptr_of(*ret, &a, &cmp_range));
}

/*static int		ft_lstlen(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}*/

/*static void		print_range(t_range r)
{
	printf("t1 : %lf\nt2 : %lf\n", r.t1.t, r.t2.t);
}

static void		print_list_range(t_list *list)
{
	ft_putnbr(ft_lstlen(list));
	ft_putchar('\n');
	while(list)
	{
		ft_putchar('\t');
		print_range(*(t_range*)(list->content));
		list = list->next;
		ft_putchar('\n');
	}
}*/

static int		difference(t_list **ret, t_range a, t_range b)
{
	t_range	n;

	set_spaces_diff(&a, &b);
	n.t1 = a.t1;
	n.t2 = a.t2;
//	printf("Longueur de liste ret : %d\n", ft_lstlen(*ret));

	/*ft_putendl("range de n :");
	print_range(n);
	ft_putendl("range de a :");
	print_range(a);
	ft_putendl("range de b :");
	print_range(b);
	printf("List range :\n");
	print_list_range(*ret);*/

	if (betweex(b.t1.t, a.t1.t , a.t2.t) && betweex(b.t2.t, a.t1.t , a.t2.t))
	{
		split_range(ret, a, b, &n);
		return (1);
	}
	else if (betweex(b.t1.t, a.t1.t , a.t2.t) && !betweex(b.t2.t, a.t1.t , a.t2.t))
	{
		n.t2 = b.t1;
		ft_lstadd(ret, ft_lstnew(&n, sizeof(t_range)));
		*ret = elem_rm(*ret, ptr_of(*ret, &a, &cmp_range));
		return (1);
	}
	else if (!betweex(b.t1.t, a.t1.t , a.t2.t) && betweex(b.t2.t, a.t1.t , a.t2.t))
	{
		n.t1 = b.t2;
		ft_lstadd(ret, ft_lstnew(&n, sizeof(t_range)));
		*ret = elem_rm(*ret, ptr_of(*ret, &a, &cmp_range));
		return (1);
	}
	else if (!betweex(b.t1.t, a.t1.t , a.t2.t) && !betweex(b.t2.t, a.t1.t , a.t2.t))
	{
		if (b.t1.t < a.t1.t && b.t2.t > a.t2.t)
		{
			*ret = elem_rm(*ret, ptr_of(*ret, &a, &cmp_range));
			return (1);
		}
	}
//	usleep(50000);
	return (0);
}

t_list		*function_difference(t_list *a, t_list *b)
{
	t_list	*ret;
	t_list	*tmp_ret;

	ret = NULL;
	while (a)
	{
		ft_lstadd(&ret, ft_lstnew(a->content, sizeof(t_range)));
		a = a->next;
	}
	tmp_ret = ret;
	while (b)
	{
		while (tmp_ret)
		{
			if (!difference(&ret,
					*((t_range*)(tmp_ret->content)),
					*((t_range*)(b->content))))
			{
				tmp_ret = tmp_ret->next;
			}
			else
				tmp_ret = ret;
		}
		b = b->next;
	}
	return (ret);
}
