/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_surface_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:45:44 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/03 19:19:25 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_vector	get_surface_normal(t_vector intersection, t_obj *tmp, t_ray ray)
{
	t_vector	n;
	double		m;
	t_vector	projection;

	if (tmp->etat == SPHERE)
		n = vec_diff(intersection, tmp->pos);
	else if (tmp->etat == PLAN)
	{
		n = tmp->n;
		if (acos(dot_product(ray.dir, tmp->n)) < M_PI_2
				&& acos(dot_product(ray.dir, tmp->n)) > -M_PI_2)
			negative_vec(&n);
	}
	else if (tmp->etat == CONE || tmp->etat == CYLINDRE)
	{
		n = vec_diff(intersection, tmp->apex);
		m = dot_product(n, tmp->axis);
		projection = n_vec(tmp->axis, m);
		n = vec_diff(n, projection);
	}
	else if (tmp->etat == CSG)
	{
		if (tmp->inter_type == SPHERE)
			n = vec_diff(intersection, tmp->pos);
		else if (tmp->inter_type == PLAN)
		{
			n = tmp->n;
			if (acos(dot_product(ray.dir, tmp->n)) < M_PI_2
					&& acos(dot_product(ray.dir, tmp->n)) > -M_PI_2)
				negative_vec(&n);
		}
		else if (tmp->inter_type == CONE || tmp->inter_type == CYLINDRE)
		{
			n = vec_diff(intersection, tmp->apex);
			m = dot_product(n, tmp->axis);
			projection = n_vec(tmp->axis, m);
			n = vec_diff(n, projection);
		}
	}
	normalize_vec(&n);
	return (n);
}
