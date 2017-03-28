#include "vector.h"

static double	get_absorb_distance(t_ray ray, t_obj *obj, t_surface s)
{
	double	back;
	double	front;
	t_list	*inter;

	front = ray.t;
	ray.org = vec_add(s.intersection, n_vec(ray.dir, 0.001));
	obj->func_obj(obj, &ray, &back, &inter);
	return (front - back);
	if (back > 0 && front < 0)
		return (back - front);
	if (back > 0 && front > 0)
		return (back - front);
	return (-back + front);
}

t_color	beers_law(t_color color, t_obj *obj, t_surface s, t_ray ray) // applied when dot_product(ray.dir, n) > 0
{
	color.red = (unsigned char)((double)color.red *
			exp(-obj->absorbtion.x
				* get_absorb_distance(ray, obj, s)));
	color.blue = (unsigned char)((double)color.blue *
			exp(-obj->absorbtion.y
				* get_absorb_distance(ray, obj, s)));
	color.green = (unsigned char)((double)color.green *
			exp(-obj->absorbtion.z
				* get_absorb_distance(ray, obj, s)));
	return (color);
}
