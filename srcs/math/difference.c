#include "rtv1.h"

int		between_ex(double t, double n1, double n2)
{
	if (n1 > n2)
		swap(&n1, &n2);
	if (t > n1 && t < n2)
		return (1);
	return (0);
}

static void	set_spaces_diff(t_range *a, t_range *b)
{
	if (a->t1.t > a->t2.t)
		swap(&a->t1.t, &a->t2.t);
	if (b->t1.t > b->t2.t)
		swap(&b->t1.t, &b->t2.t);
	//printf("structure a : a.t1 = %lf --- a.t2 = %lf\n", a->t1, a->t2);
	//printf("structure b : b.t1 = %lf --- b.t2 = %lf\n\n", b->t1, b->t2);
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

static int		difference(t_list **ret, t_range a, t_range b)
{
	t_range	n;

	// on a tjrs list a moins list b
	set_spaces_diff(&a, &b);
	//a.t1 < a.t2 et b.t1 < b.t2
	//printf("struct b : b.t1 = %lf --- b.t2 = %lf\n", b.t1, b.t2);
	//printf("struct a : a.t1 = %lf --- a.t2 = %lf\n", a.t1, a.t2);
	//printf("struct n : n.t1 = %lf --- n.t2 = %lf\n\n", n.t1, n.t2);
	if (between_ex(b.t1.t, a.t1.t , a.t2.t) && between_ex(b.t2.t, a.t1.t , a.t2.t))
	{
		n.t1 = a.t1;
		n.t2 = b.t1;
		ft_lstadd(ret, ft_lstnew(&n, sizeof(t_range)));
		n.t1 = b.t2;
		n.t2 = a.t2;
		ft_lstadd(ret, ft_lstnew(&n, sizeof(t_range)));
		*ret = elem_rm(*ret, ptr_of(*ret, &a, &cmp_range));
		return (2);
	}
	if (between_ex(b.t1.t, a.t1.t , a.t2.t) && !between_ex(b.t2.t, a.t1.t , a.t2.t))
	{
		n.t1 = a.t1;
		n.t2 = b.t1;
		ft_lstadd(ret, ft_lstnew(&n, sizeof(t_range)));
		*ret = elem_rm(*ret, ptr_of(*ret, &a, &cmp_range));
		return (1);
	}
	if (!between_ex(b.t1.t, a.t1.t , a.t2.t) && between_ex(b.t2.t, a.t1.t , a.t2.t))
	{
		n.t1 = b.t2;
		n.t2 = a.t2;
		ft_lstadd(ret, ft_lstnew(&n, sizeof(t_range)));
		*ret = elem_rm(*ret, ptr_of(*ret, &a, &cmp_range));
		return (1);
	}
	if (!between_ex(b.t1.t, a.t1.t , a.t2.t) && !between_ex(b.t2.t, a.t1.t , a.t2.t))
	{
		if (b.t1.t < a.t1.t && b.t2.t > a.t2.t)
		{
			*ret = elem_rm(*ret, ptr_of(*ret, &a, &cmp_range));
			return (1);
		}
	}
	return (0);
}

t_list	*function_difference(t_list *a, t_list *b)
{
	t_list	*ret;
	t_list	*tmp_ret;

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
			difference(&ret, *((t_range*)(tmp_ret->content)), *((t_range*)(b->content)));
			tmp_ret = tmp_ret->next;
		}
		b = b->next;
	}
	return (ret);
}
