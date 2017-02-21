#include "rtv1.h"

t_ray	get_reflection(t_surface s, t_ray ray)
{
	t_ray	r;

	r.dir = vec_diff(ray.dir, n_vec(s.n, 2 * dot_product(s.n, ray.dir)));
	r.org = s.intersection;
	return (r);
}
