#include "rtv1.h"

t_ray	get_refraction(t_surface s, t_ray ray)
{
	t_ray	t;
	double	div;
	double	c1;
	double	c2;
	double	k;

	div = 2;
	c1 = dot_product(s.n, ray.dir);
	c2 = sqrt(1 - (div * div) * sin(c1));
	t.dir = vec_add(n_vec(ray.dir, div), n_vec(s.n, div * c1 - c2));
	if (c1 >= 0)
	{
		negative_vec(&s.n);
	}	
	else //outside
	{
		c1 = -c1;
	}
	k = 1 - div * div * (1 - cos(c1) * cos(c1));
//	if (k < 0)
//		return ;
//	else	
		return (t);
}
