/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:23:04 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/06 13:23:06 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>
#include "rtv1.h"

static void		get_smaller_t(t_list *lst, t_obj **obj, double *t)
{
	t_range		*tmp;

	*t = 2000000;
	while (lst)
	{
		tmp = (t_range*)(lst->content);
		if ((tmp->t1.t <= *t) && (tmp->t1.t > ZERO))
		{
			*t = tmp->t1.t;
			*obj = tmp->t1.obj;
		}
		if ((tmp->t2.t <= *t) && (tmp->t2.t > ZERO))
		{
			*t = tmp->t2.t;
			*obj = tmp->t2.obj;
		}
		lst = lst->next;
	}
}

static void		del_range(void *content, size_t size)
{
	(void)size;
	free(content);
}

static int		kill(t_list **a, t_list **b)
{
	if (*a)
		ft_lstdel(a, &del_range);
	if (*b)
		ft_lstdel(b, &del_range);
	return (0);
}

int				csg(t_obj *obj, t_ray *ray, double *t, t_list **inter)
{
	t_list		*tmp_list;
	t_list		*a;
	t_list		*b;
	t_obj		*obj_thread;
	t_list		*list;

	a = NULL;
	b = NULL;
	if (!(tmp_list = obj->csg))
		return (kill(&a, &b));
	obj_thread = (t_obj*)tmp_list->content;
	obj_thread->func_obj(obj_thread, ray, t, &b);
	if (!(tmp_list = tmp_list->next))
		return (kill(&a, &b));
	obj_thread = (t_obj*)tmp_list->content;
	obj_thread->func_obj(obj_thread, ray, t, &a);
	list = (obj->type == DIFFERENCE) ? (f_d(a, b)) : (f_i(a, b));
	get_smaller_t(list, &obj_thread, t);
	if (!obj_thread || !list)
		return (kill(&a, &b));
	obj->pointeur[ray->thread] = obj_thread;
	ft_lstdel(&a, &del_range);
	ft_lstdel(&b, &del_range);
	(!inter) ? ft_lstdel(&list, &del_range) : (*inter = list);
	return (1);
}
