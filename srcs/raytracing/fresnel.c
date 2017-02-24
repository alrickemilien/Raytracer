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
	double	etai;
	double	etat;
	double	n;
	double	sin_t;
	double	cos_x;
	double	x;
	double ret;

	etai = 1;
	etat = s.refraction;
	r0 = (etai - etat) / (etai + etat);
	r0 *= r0;
	cos_x = -dot_product(s.n, ray.dir);
	if (etai > etat)
	{
		n = etai / etat;
		sin_t = n * n * (1 - cos_x);
		if (sin_t >= 1)
			return (1);
		cos_x = sqrt(1 - sin_t);
	}
	x = 1 - cos_x;
	ret = r0 + (1 - r0)*x*x*x*x*x;
	return (0.8 + (1 - 0.8) * ret);

/*	double	cos_in;
	double	sin_tn;
	double	cos_tn;

	double	etai;
	double	etat;

	double	rs;
	double	rp;

	etai = 1;
	etat = s.refraction;
	cos_in = dot_product(ray.dir, s.n);
	if (cos_in > 0)
		ft_dswap(&etai, &etat);
	sin_tn = (etai / etat) * (etai / etat) * sqrt(ft_dtrim(0, 1, 1 - cos_in * cos_in));
	if (sin_tn >= 1)
		return (1);
	cos_tn = sqrt(ft_dtrim(0, 1, 1 - sin_tn));
	cos_in = ft_dabs(cos_in);
	rs = ((etat * cos_in) - (etai * cos_tn)) / ((etat * cos_in) + (etai *cos_tn));
	rp = ((etai * cos_in) - (etat * cos_tn)) / ((etai * cos_in) + (etat *cos_tn));
//	printf("rs : %lf\n", (rs * rs + rp *rp) / 2);
	return ((rs * rs + rp *rp) / 2);*/
}
