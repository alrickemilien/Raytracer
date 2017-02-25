#include "rtv1.h"

void	set_color_coeff(t_env *env, t_surface s,
		t_obj *tmp, double *t)
{
	t_vector	light_dir;
	t_list		*tmp_light;
	t_ray		ray;
	double		shadow_ret;

	tmp_light = env->light;
	while (tmp_light)
	{
		light_dir = vec_diff(LIGHT_PTR->org, s.intersection);
		s.diffuse = get_diffuse(s.n, light_dir) * LIGHT_PTR->diffuse;
		ray.org = vec_add(s.intersection, n_vec(s.n, 0.0001));
		ray.dir = vec_diff(LIGHT_PTR->org, ray.org);
		s.spec = get_specularity(s.intersection, s.n, light_dir, tmp)
			* LIGHT_PTR->specular;
		shadow_ret = shadow(env, ray, light_dir.norme);
		s.spec *= shadow_ret;
		s.diffuse *= shadow_ret;
		*t += ft_dtrim(0, 1, (LIGHT_PTR->intensity / light_dir.norme)
				* (s.diffuse + s.spec));
		tmp_light = tmp_light->next;
	}
	*t += env->k;
}
