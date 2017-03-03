#include "../include/rtv1.h"

int				cone(t_obj *cone, t_ray *ray, double *t, t_list **inter)
{
	t_vector	coeffs;
	double		delta;
	t_vector	tmp;
	t_vector	x;
	t_range		range;

	x = vec_diff(ray->org, cone->apex);
	coeffs.x = dot_product(ray->dir, ray->dir) - (1 + cone->angle)
		* dot_product(ray->dir, cone->axis) * dot_product(ray->dir, cone->axis);
	delta = dot_product(ray->dir, x);
	coeffs.y = (delta + delta) - (1 + cone->angle)
		* dot_product(ray->dir, cone->axis)
		* dot_product(x, cone->axis) * (double)2;
	coeffs.z = dot_product(x, x) - (1 + cone->angle)
		* dot_product(x, cone->axis) * dot_product(x, cone->axis);
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
	ft_lstadd(inter, ft_lstnew(&range, sizeof(double)));
	return (1);
}
