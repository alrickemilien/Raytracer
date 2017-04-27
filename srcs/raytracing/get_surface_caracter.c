/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_surface_caracter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:32 by aemilien          #+#    #+#             */
/*   Updated: 2017/04/27 16:12:03 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_surface			get_surface_caracter(t_ray ray, t_obj *tmp)
{
	t_surface	s;

	s.intersection = vec_add(n_vec(ray.dir, ray.t), ray.org);
	s.n = get_surface_normal(s.intersection, tmp, ray);
	normalize_vec(&s.n);
	s.refraction = tmp->refraction;
	s.reflection = tmp->reflection;
	s.transparent = tmp->transparent;
	return (s);
}
