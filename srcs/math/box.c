#include "vector.h"
#include "rtv1.h"

static int		set_range(t_list **inter, t_inter *plans)
{
	t_range		range;

	if (!inter)
		return (1);
	range.t1 = plans[0];
	range.t2 = plans[1];
	ft_lstadd(inter, ft_lstnew(&range, sizeof(t_range)));
	return (1);
}

static int		belong_to_box(double t, t_obj obj, t_ray *ray)
{
	t_vector	inter;

	inter = vec_diff(vec_add(ray->org, n_vec(ray->dir, t)), obj.pos);
	inter = product_vec_matrix(obj.matrix, inter);
	if (inter.x >= -obj.size - 0.0001 && inter.x <= obj.size + 0.0001 &&
		inter.y >= -obj.size - 0.0001 && inter.y <= obj.size + 0.0001 &&
		inter.z >= -obj.size - 0.0001 && inter.z <= obj.size + 0.0001)
		return (1);
	return (0);
}

static int		are_close(t_inter *plans, int i, double bias)
{
	int j;

	j = -1;
	while (++j < i)
		if (plans[i].t >= plans[j].t - bias && plans[i].t <= plans[j].t + bias)
			return (1);
	return (0);
}

static int		check_box(t_list *tmp, t_inter *plans, t_obj *obj, t_ray *ray)
{
	int i;

	i = 0;
	while (tmp)
	{
		if (plan((t_obj*)tmp->content, ray, &(plans[i]).t, NULL)
			&& belong_to_box(plans[i].t, *obj, ray))
		{
			if (!are_close(plans, i, 0.001))
			{
				plans[i].obj = (t_obj*)tmp->content;
				i++;
			}
		}
		if (i > 1)
			return (i);
		tmp = tmp->next;
	}
	return (i);
}

int				box(t_obj *obj, t_ray *ray, double *t, t_list **inter)
{
	t_list		*tmp;
	t_inter		*plans;

	if (!(plans = (t_inter*)ft_memalloc(sizeof(t_inter) * 2)))
		merror();
	tmp = obj->csg;
	*t = 200000;
	if (check_box(tmp, plans, obj, ray) < 2)
	{
		free(plans);
		return (0);
	}
	*t = plans[0].t;
	obj->pointeur[ray->thread] = plans[0].obj;
	if (*t > plans[1].t)
	{
		*t = plans[1].t;
		obj->pointeur[ray->thread] = plans[1].obj;
	}
	set_range(inter, plans);
	free(plans);
	return (1);
}
