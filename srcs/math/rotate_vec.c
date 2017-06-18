/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:04:22 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/06 13:26:18 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static double		*set_rotation_matrix_cam(double *matrix,
							double alpha, double beta, double gamma)
{
	t_matrix_rot	coeffs;

	coeffs.a = cos(alpha);
	coeffs.b = sin(alpha);
	coeffs.c = cos(beta);
	coeffs.d = sin(beta);
	coeffs.e = cos(gamma);
	coeffs.f = sin(gamma);
	coeffs.ad = coeffs.a * coeffs.d;
	coeffs.bd = coeffs.b * coeffs.d;
	matrix[0] = coeffs.c * coeffs.e;
	matrix[1] = -coeffs.c * coeffs.f;
	matrix[2] = coeffs.d;
	matrix[4] = coeffs.bd * coeffs.e + coeffs.a * coeffs.f;
	matrix[5] = -coeffs.bd * coeffs.f + coeffs.a * coeffs.e;
	matrix[6] = -coeffs.b * coeffs.c;
	matrix[8] = -coeffs.ad * coeffs.e + coeffs.b * coeffs.f;
	matrix[9] = coeffs.ad * coeffs.f + coeffs.b * coeffs.e;
	matrix[10] = coeffs.a * coeffs.c;
	matrix[15] = 1;
	return (matrix);
}

void				rotate_vec(t_vector rot, t_vector *vector)
{
	double			*m;

	m = (double*)ft_memalloc(sizeof(double) * 16);
	m = set_rotation_matrix_cam(m, rot.x,
					rot.y, rot.z);
	*vector = product_vec_matrix(m, *vector);
	free(m);
}
