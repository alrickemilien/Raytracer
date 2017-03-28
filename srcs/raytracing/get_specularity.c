/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specularity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:27 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/24 18:29:28 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static double	rec_spec(int max, double spec, double angle)
{
	int			i;

	i = -1;
	while (++i < max)
		spec *= angle;
	return (spec);
}

double			get_specularity(t_vector intersection, t_vector n,
								t_vector light_dir, t_obj *obj)
{
	t_vector	r;
	double		tmp;
	double		angle;
	t_vector	v;

	normalize_vec(&intersection);
	v = light_dir;
	tmp = dot_product(light_dir, n);
	normalize_vec(&light_dir);
	r = vec_diff(v, n_vec(n, (tmp + tmp)));
	normalize_vec(&r);
	if ((angle = dot_product(r, intersection)) < 0)
		return (0);
	return (rec_spec(obj->brillance, obj->specular, angle));
}
