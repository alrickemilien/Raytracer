/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_surface_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:45:44 by aemilien          #+#    #+#             */
/*   Updated: 2017/04/24 14:33:15 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static t_vector		normal_c(t_obj *tmp, t_vector inter)
{
	t_vector		projection;
	t_vector		n;
	double			m;

	n = vec_diff(inter, tmp->apex);
	m = dot_product(n, tmp->axis);
	projection = n_vec(tmp->axis, m);
	n = vec_diff(n, projection);
	return (n);
}

static t_vector		normal_p(t_obj *tmp, t_ray ray)
{
	t_vector		n;

	n = tmp->n;
	if (acos(dot_product(ray.dir, tmp->n)) < M_PI_2
			&& acos(dot_product(ray.dir, tmp->n)) > -M_PI_2)
		negative_vec(&n);
	return (n);
}

t_vector			get_surface_normal(t_vector inter, t_obj *tmp, t_ray ray)
{
	t_vector		n;

	if (tmp->etat == SPHERE)
		n = vec_diff(inter, tmp->pos);
	else if (tmp->etat == PLAN)
		n = normal_p(tmp, ray);
	else if (tmp->etat == CONE || tmp->etat == CYLINDRE)
		n = normal_c(tmp, inter);
	else if (tmp->etat == CSG)
	{
		if (tmp->inter_type == SPHERE)
			n = vec_diff(inter, tmp->pos);
		else if (tmp->inter_type == PLAN)
			n = normal_p(tmp, ray);
		else if (tmp->inter_type == CONE || tmp->inter_type == CYLINDRE)
			n = normal_c(tmp, inter);
	}
	normalize_vec(&n);
	return (n);
}
