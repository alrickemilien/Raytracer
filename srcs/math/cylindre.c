#include "../include/rtv1.h"

static void		set_range(t_list **inter, t_obj *obj, double t1, double t2)
{
	t_range		range;

	range.t1 = (t_inter){t1, obj};
	range.t2 = (t_inter){t2, obj};
	ft_lstadd(inter, ft_lstnew(&range, sizeof(t_range)));
}

static int	check_size(t_obj *cylindre, t_ray *ray, t_vector inter, t_obj **ptr)
{
	double	inter_plan[2];
	int		ret[2];

	ft_bzero(inter_plan, 2 * sizeof(double));
	if (cylindre->size > 20000)	
		return (1);
	ret[0] = plan(cylindre->csg->next->content, ray, &inter_plan[0], NULL);
	ret[1] = plan(cylindre->csg->content, ray, &inter_plan[1], NULL);
	if ((inter.x <= inter_plan[0] && inter.x >= inter_plan[1])
		|| (inter.x <= inter_plan[1] && inter.x >= inter_plan[0]))
	{
		if ((inter_plan[0] <= inter.x && inter_plan[0] >= inter.y)
		|| (inter_plan[0] >= inter.x && inter_plan[0] <= inter.y))
			*ptr = (t_obj*)cylindre->csg->next->content;
		if (inter.x > inter.y && ret[0] >= ret[1])
			*ptr = (t_obj*)cylindre->csg->content;
		return (1);
	}
	if ((inter.y <= inter_plan[0] && inter.y >= inter_plan[1])
		|| (inter.y <= inter_plan[1] && inter.y >= inter_plan[0]))
	{
		if (inter.y > inter.x && ret[0] < ret[1])
			*ptr = (t_obj*)cylindre->csg->next->content;
		if (inter.y > inter.x && ret[0] >= ret[1])
			*ptr = (t_obj*)cylindre->csg->content;
		return (1);
	}
	return (0);
}

int		cylindre(t_obj *cylindre, t_ray *ray, double *t, t_list **inter)
{
	t_vector	coeffs;
	double		delta;
	t_vector	tmp;
	t_vector	x;

	x = vec_diff(ray->org, cylindre->apex);
	coeffs.x = dot_product(ray->dir, ray->dir)
		- dot_product(ray->dir, cylindre->axis)
		* dot_product(ray->dir, cylindre->axis);
	delta = dot_product(ray->dir, x);
	coeffs.y = (delta + delta) - dot_product(ray->dir, cylindre->axis)
		* dot_product(x, cylindre->axis) * (double)2;
	coeffs.z = dot_product(x, x) - dot_product(x, cylindre->axis)
		* dot_product(x, cylindre->axis) - cylindre->r * cylindre->r;
	if ((delta = (coeffs.y * coeffs.y) - ((double)4 * coeffs.x * coeffs.z)) < 0)
		return (0);
	tmp.x = ((double)((-coeffs.y - sqrt(delta)) / (coeffs.x + coeffs.x)));
	tmp.y = ((double)((-coeffs.y + sqrt(delta)) / (coeffs.x + coeffs.x)));
	*t = tmp.y;
	if (tmp.x < tmp.y && tmp.x >= 0)
		*t = tmp.x;
	if (*t < 0)
		return (0);
	cylindre->pointeur[ray->thread] = cylindre;
	if (!check_size(cylindre, ray, tmp, cylindre->pointeur + ray->thread ))
		return (0);
	if (inter)
		set_range(inter, cylindre, tmp.x, tmp.y);
	return (1);
}
