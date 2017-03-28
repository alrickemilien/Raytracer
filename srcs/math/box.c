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

int		belong_to_box(double t, t_obj obj, t_ray *ray)
{
	t_vector	intersection;

	intersection = vec_diff(vec_add(ray->org, n_vec(ray->dir, t)), obj.pos);
	intersection = product_vec_matrix(obj.matrix, intersection);
	if (intersection.x >= obj.bounds[0].x - 0.0001 && intersection.x <= obj.bounds[1].x + 0.0001 &&
		intersection.y >= obj.bounds[0].y - 0.0001 && intersection.y <= obj.bounds[1].y + 0.0001 &&
		intersection.z >= obj.bounds[0].z - 0.0001 && intersection.z <= obj.bounds[1].z + 0.0001)
		return (1);
	return (0);
}

int		are_close(double a, double b, double bias)
{

	if (a >= b - bias && a <= b + bias)
		return (1);
	return (0);
}

int		box(t_obj *obj, t_ray *ray, double *t, t_list **inter)
{
	t_inter		plans[2];
	t_list		*tmp;
	int			i;
	int			j;
	int			k;

	ft_bzero(plans, sizeof(t_inter) * 2);
	tmp = obj->csg;
	*t = 200000;
	i = 0;
	while (tmp)
	{
		k = 0;
		if (plan((t_obj*)tmp->content, ray, &plans[i].t, NULL)
				&& belong_to_box(plans[i].t, *obj, ray))
		{
			j = 0;
			while (j < i)
			{
				if (are_close(plans[i].t, plans[j].t, 0.001))
				{
					k = 1;
					break ;
				}
				j++;
			}
			if (!k)
			{
				plans[i].obj = (t_obj*)tmp->content;
				i++;
			}
		}
		if (i > 1)
			break ;
		tmp = tmp->next;
	}
	if (i < 2)
		return (0);
	*t = plans[0].t;
	obj->pointeur[ray->thread] = plans[0].obj;
	if (*t > plans[1].t)
	{
		*t = plans[1].t;
		obj->pointeur[ray->thread] = plans[1].obj;
	}
	set_range(inter, plans);
	return (1);
}
