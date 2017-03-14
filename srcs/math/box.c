#include "../include/rtv1.h"

static int		set_range(t_list **inter, t_inter *plans, double *t)
{
	t_range		range;

	if (!inter)
		return (1);
	range.t1 = (t_inter){t1, obj};
	range.t2 = (t_inter){t2, obj};
	ft_lstadd(inter, ft_lstnew(&range, sizeof(t_range)));
	return (1);
}

int		box(t_obj *obj, t_ray *ray, double *t, t_list **inter)
{
	t_inter		plans[4];
	t_list		*tmp;
	int			i;

	ft_bzero(plans, sizeof(t_inter) * 4);
	tmp = obj->csg;
	*t = 200000;
	obj->pointeur[ray->thread] = NULL;
	i = 0;
	while (tmp)
	{
		if (plan((t_obj*)tmp->content, ray, &plans[i].t, NULL))
		{
			plans[i].obj = (t_obj*)tmp->content;
			i++;
		}
		tmp = tmp->next;
	}
	if (i > 4)
		return (set_range(inter, plans, t));
	if (i < 4 && dot_product(plans[0].obj->n, plans[1].obj->n) < 0.001)
		return (1);
	return (0);
}
