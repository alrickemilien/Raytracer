#include "../include/rtv1.h"

int		cylindre(t_obj *cylindre, t_ray *ray, double *t, t_list **inter)
{
	t_vector	coeffs;
	double		delta;
	t_vector	tmp;
	t_vector	x;
	t_range		range;

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
	range.t1 = (t_inter){tmp.x, obj};
	range.t2 = (t_inter){tmp.y, obj};
	ft_lstadd(inter, ft_lstnew(&range, sizeof(t_range)));
	return (1);
}
