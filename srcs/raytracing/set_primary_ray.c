/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_primary_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbellahc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:49:13 by wbellahc          #+#    #+#             */
/*   Updated: 2017/05/06 13:49:15 by wbellahc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "vector.h"

void			set_primary_ray(t_env *env, t_ray *ray, double j, double i)
{
	t_vector	null_vector;

	ray->dir.x = ((double)2 * ((j + 0.5) /
				(double)env->image->width) - (double)1)
		* env->scale * env->image_aspect_ratio;
	ray->dir.y = ((double)1 - (double)2 * ((i + 0.5) /
				(double)env->image->height)) * env->scale;
	ray->dir.z = -1;
	ray->dir = product_matrix4x4(env->select->c->matrix, ray->dir);
	normalize_vec(&ray->dir);
	ft_bzero(&null_vector, sizeof(t_vector));
	ray->org = product_vec_matrix(env->select->c->matrix,
			null_vector);
	ray->coeff = 1;
	ray->thread = env->nb_thread;
}
