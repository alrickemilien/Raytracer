#include "rtv1.h"

int		light_obj(t_obj *obj, t_ray *ray, double *t, t_list **inter)
{
	t_vector	light_dist;
	double		coeff;

	light_dist = vec_diff(light->pos, ray->org);
	coeff = exp(-dot_product(ray->dir, light_dist)) * light->intensity;
	if ()
}
