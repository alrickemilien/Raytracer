#include "rtv1.h"

t_ray	get_refraction(t_surface s, t_ray ray)
{
	t_ray	t;
	double	div;
	double	c1;
	double	k;
	double	original_n;
	double	new_n;

	t.thread = ray.thread;
	normalize_vec(&ray.dir);
	if ((c1 = dot_product(s.n, ray.dir)) > 0) // c'est qu on sort
	{
		original_n = s.refraction;
		new_n = 1;
		negative_vec(&s.n);
	}
	else
	{
		c1 = -c1;
		original_n = 1;
		new_n = s.refraction;
	}
	div = original_n / new_n;
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
