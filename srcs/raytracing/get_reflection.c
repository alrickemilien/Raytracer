/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbellahc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:48:35 by wbellahc          #+#    #+#             */
/*   Updated: 2017/05/06 13:48:37 by wbellahc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_ray		get_reflection(t_surface s, t_ray ray)
{
	t_ray	r;

	r.dir = vec_diff(ray.dir, n_vec(s.n, 2 * dot_product(s.n, ray.dir)));
	r.thread = ray.thread;
	normalize_vec(&r.dir);
	if (dot_product(ray.dir, s.n) < 0)
		r.org = vec_add(s.intersection, n_vec(r.dir, 0.0001));
	else
		r.org = vec_add(s.intersection, n_vec(r.dir, -0.0001));
	return (r);
}
