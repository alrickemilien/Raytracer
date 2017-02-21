/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:46:11 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:46:11 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

double	*set_rotation_matrix(double *matrix,
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
	ft_memset(matrix, 0, sizeof(double) * 16);
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

void	rotate_object(t_obj *object, t_vector *vector)
{
	double	*m;

	m = (double*)malloc(sizeof(double) * 16);
	m = set_rotation_matrix(m, object->rotation.x,
					object->rotation.y, object->rotation.z);
	*vector = product_vec_matrix(m, *vector);
	free(m);
}
