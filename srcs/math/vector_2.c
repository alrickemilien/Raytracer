/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:46:30 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:46:31 by aemilien         ###   ########.fr       */
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
