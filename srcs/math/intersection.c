/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:25:56 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/06 13:25:57 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static void	swap_object(t_range *a, t_range *b)
{
	t_obj	*tmp;

	tmp = a->t1.obj;
	a->t1.obj = b->t1.obj;
	b->t1.obj = tmp;
	tmp = a->t2.obj;
	a->t2.obj = b->t2.obj;
	b->t2.obj = tmp;
}

static void	set_spaces(t_range *a, t_range *b)
{
	if (range(a->t1.t, a->t2.t) < range(b->t1.t, b->t2.t))
	{
		swap(&a->t1.t, &b->t1.t);
		swap(&a->t2.t, &b->t2.t);
		swap_object(a, b);
	}
	if (a->t1.t > a->t2.t)
		swap(&a->t1.t, &a->t2.t);
	if (b->t1.t > b->t2.t)
		swap(&b->t1.t, &b->t2.t);
}

static void	intersection(t_list **ret, t_range a, t_range b)
{
	t_range		n;
	int			k;

	set_spaces(&a, &b);
	k = 0;
	n.t1 = a.t1;
	if (betwn(b.t1.t, a.t1.t, a.t2.t))
	{
		k = 1;
		n.t1 = b.t1;
	}
	n.t2 = a.t2;
	if (betwn(b.t2.t, a.t1.t, a.t2.t))
	{
		k = 1;
		n.t2 = b.t2;
	}
	if (k)
		ft_lstadd(ret, ft_lstnew(&n, sizeof(t_range)));
}

t_list		*f_i(t_list *a, t_list *b)
{
	t_list	*ret;
	t_list	*tmp_b;

	ret = NULL;
	while (a)
	{
		tmp_b = b;
		while (tmp_b)
		{
			intersection(&ret,
					*((t_range*)(a->content)),
					*((t_range*)(tmp_b->content)));
			tmp_b = tmp_b->next;
		}
		a = a->next;
	}
	return (ret);
}
