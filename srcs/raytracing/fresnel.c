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
	double	cos_in;
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
	sin_tn = etai / etat * sqrt(ft_dtrim(0, 1, 1 - cos_in * cos_in));
	if (sin_tn >= 1)
		return (1);
	cos_tn = sqrt(ft_dtrim(0, 1, 1 - sin_tn * sin_tn));
	cos_in = ft_dabs(cos_in);
	rs = ((etat * cos_in) - (etai * cos_tn)) / ((etat * cos_in) + (etai *cos_tn));
	rp = ((etai * cos_in) - (etat * cos_tn)) / ((etai * cos_in) + (etat *cos_tn));
//	printf("rs : %lf\n", (rs * rs + rp *rp) / 2);
	return ((rs * rs + rp *rp) / 2);
}
