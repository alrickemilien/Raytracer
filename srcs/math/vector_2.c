/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:46:30 by aemilien          #+#    #+#             */
/*   Updated: 2017/04/22 15:42:30 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector		vec_diff(t_vector a, t_vector b)
{
	t_vector	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	v.norme = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (v);
}

t_vector		vec_add(t_vector a, t_vector b)
{
	t_vector	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	v.norme = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (v);
}

void			negative_vec(t_vector *v)
{
	v->x = -v->x;
	v->y = -v->y;
	v->z = -v->z;
}

int				is_vectornull(t_vector v)
{
	if (!v.x && !v.y && !v.z)
		return (1);
	return (0);
}

t_vector		get_vec(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.norme = sqrt((x * x)
			+ (y * y)
			+ (z * z));
	return (v);
}
