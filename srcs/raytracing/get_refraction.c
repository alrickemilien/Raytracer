#include "rtv1.h"

t_ray	get_refraction(t_surface s, t_ray ray)
{
	t_ray	t;
	double	div;
	double	c1;
	double	k;

	c1 = dot_product(s.n, ray.dir);
	if (c1 >= 0) // outside
	{
		div = s.refraction / 1;
		negative_vec(&s.n);
	}	
	else //inside
	{
		div = 1 / s.refraction;
		c1 = -c1;
	}
	k = 1 - div * div * (1 - cos(c1) * cos(c1));
	if (k < 0)
		ft_bzero(&t.dir, sizeof(t_vector));
	else	
	{
		t.dir = vec_add(n_vec(ray.dir, div), n_vec(s.n, div * c1 - sqrt(k)));
		normalize_vec(&t.dir);
		if (dot_product(ray.dir, s.n) < 0)
			t.org = vec_add(s.intersection, n_vec(s.n, -0.0001));
		else
			t.org = vec_add(s.intersection, n_vec(s.n, 0.0001));
		t.coeff = 1 - ray.coeff;
	}
	return (t);
}
