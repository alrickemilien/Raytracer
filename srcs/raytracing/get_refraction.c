#include "vector.h"

t_ray		get_refraction(t_surface s, t_ray ray)
{
	t_ray	t;
	double	div;
	double	c1;
	double	k;
	double	original_n;

	t.thread = ray.thread;
	normalize_vec(&ray.dir);
	c1 = dot_product(s.n, ray.dir);
	original_n = c1 > 0 ? s.refraction : 1;
	k = c1 > 0 ? 1 : s.refraction;
	if (c1 > 0)
		negative_vec(&s.n);
	c1 = c1 > 0 ? c1 : -c1;
	div = original_n / k;
	k = 1 - div * div * (1 - c1 * c1);
	if (k < 0)
		ft_bzero(&t.dir, sizeof(t_vector));
	else
	{
		t.dir = vec_add(n_vec(ray.dir, div), n_vec(s.n, div * c1 - sqrt(k)));
		normalize_vec(&t.dir);
		t.org = vec_add(s.intersection, n_vec(t.dir, 0.001));
	}
	return (t);
}
