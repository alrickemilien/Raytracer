/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:46:23 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:46:24 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			set_vec(t_vector *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
	v->norme = sqrt((x * x) + (y * y) + (z * z));
}

t_vector		cross_product(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = (a.y * b.z) - (a.z * b.y);
	result.y = (a.z * b.x) - (a.x * b.z);
	result.z = (a.x * b.y) - (a.y * b.x);
	result.norme = sqrt((result.x * result.x)
						+ (result.y * result.y)
						+ (result.z * result.z));
	return (result);
}

double			dot_product(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

void			normalize_vec(t_vector *v)
{
	if (!v->norme)
		return ;
	v->x = v->x / v->norme;
	v->y = v->y / v->norme;
	v->z = v->z / v->norme;
	v->norme = sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
}

t_vector		n_vec(t_vector from, double n)
{
	t_vector	v;

	v.x = from.x * n;
	v.y = from.y * n;
	v.z = from.z * n;
	v.norme = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (v);
}
