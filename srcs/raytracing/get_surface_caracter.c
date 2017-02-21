/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_surface_caracter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:32 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/21 13:46:00 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_surface			get_surface_caracter(t_env *env, t_ray ray,
									t_obj *tmp, double *t)
{
	t_surface	s;
	t_vector	light_dir;
	t_list		*tmp_light;
	t_ray		tmp_ray;

	tmp_light = env->light;
	while (tmp_light)
	{
		s.intersection = vec_add(n_vec(ray.dir, ray.t), ray.org);
		s.n = get_surface_normal(s.intersection, tmp, ray);
		tmp_ray = ray;
		light_dir = vec_diff(LIGHT_PTR->org, s.intersection);
		s.diffuse = get_diffuse(s.n, light_dir) * LIGHT_PTR->diffuse;
		tmp_ray.org = vec_add(s.intersection, n_vec(s.n, 0.0001));
		tmp_ray.dir = vec_diff(LIGHT_PTR->org, tmp_ray.org);
		s.spec = get_specularity(s.intersection, s.n, light_dir, tmp)
			* LIGHT_PTR->specular;
		if (shadow(env, tmp_ray, light_dir.norme) != 1)
			ft_bzero(&s, sizeof(s));
		*t += ft_dtrim(0, 1, (LIGHT_PTR->intensity / light_dir.norme)
				* (s.diffuse + s.spec));
		tmp_light = tmp_light->next;
	}
	return (s);
}
