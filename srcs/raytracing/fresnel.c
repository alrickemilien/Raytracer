#include "vector.h"

void		ft_dswap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

double		fresnel(t_ray ray, t_surface s)
{
	double v[8];

	v[COS_X] = dot_product(s.n, ray.dir);
	(v[ORIG_N]) = (v[COS_X] < 0) ? (1) : (s.refraction);
	(v[NEW_N]) = (v[ORIG_N] != 1) ? (1) : (s.refraction);
	v[R0] = (v[ORIG_N] - v[NEW_N]) / (v[ORIG_N] + v[NEW_N]);
	v[R0] *= v[R0];
	v[COS_X] = -dot_product(s.n, ray.dir);
	if (v[ORIG_N] > v[NEW_N])
	{
		v[N] = v[ORIG_N] / v[NEW_N];
		v[SIN_T] = v[N] * v[N] * (1 - v[COS_X] * v[COS_X]);
		if (v[SIN_T] >= 1)
			return (1);
		v[COS_X] = sqrt(1 - v[SIN_T]);
	}
	v[X] = 1 - v[COS_X];
	v[RET] = v[R0] + (1 - v[R0]) * v[X] * v[X] * v[X] * v[X] * v[X];
	return ((1 - s.transparent) - (1 - (1 - s.transparent)) * v[RET]);
}
