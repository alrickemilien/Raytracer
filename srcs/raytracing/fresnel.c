#include "rtv1.h"

void	ft_dswap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

double	fresnel(t_ray ray, t_surface s)
{

	double	r0;
	double	original_n;
	double	new_n;
	double	n;
	double	sin_t;
	double	cos_x;
	double	x;
	double ret;

	if ((cos_x = dot_product(s.n, ray.dir)) < 0)
	{
		original_n = 1;
		new_n = s.refraction;
	}
	else
	{
		original_n = s.refraction;
		new_n = 1;
	}
	r0 = (original_n - new_n) / (original_n + new_n);
	r0 *= r0;
	cos_x = -dot_product(s.n, ray.dir);
	if (original_n > new_n)
	{
		n = original_n / new_n;
		sin_t = n * n * (1 - cos_x * cos_x);
		if (sin_t >= 1)
			return (1);
		cos_x = sqrt(1 - sin_t);
	}
	x = 1 - cos_x;
	ret = r0 + (1 - r0)*x*x*x*x*x;
	return (ret);

/*	double	cos_in;
	double	sin_tn;
	double	cos_tn;

	double	original_n;
	double	new_n;

	double	rs;
	double	rp;

	if ((cos_in = dot_product(s.n, ray.dir)) < 0)
	{
		original_n = 1;
		new_n = s.refraction;
	}
	else
	{
		original_n = s.refraction;
		new_n = 1;
	}
	cos_in = -cos_in;
	sin_tn = (original_n / new_n) * (original_n / new_n) *  (1 - cos_in * cos_in);
	if (sin_tn >= 1)
		return (1);
	cos_tn = sqrt( 1-  sin_tn);
	cos_in = ft_dabs(cos_in);
	rs = ((new_n * cos_in) - (original_n * cos_tn)) / ((new_n * cos_in) + (original_n *cos_tn));
	rp = ((original_n * cos_in) - (new_n * cos_tn)) / ((original_n * cos_in) + (new_n *cos_tn));
//	printf("rs : %lf\n", (rs * rs + rp *rp) / 2);
	return ((rs * rs + rp *rp) / 2);*/
}
