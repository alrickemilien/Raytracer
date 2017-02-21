/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:45:53 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:45:54 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector		product_matrix4x4(double *m, t_vector v)
{
	t_vector	vec_result;

	vec_result.x = v.x * m[0]
		+ v.y * m[4]
		+ v.z * m[8];
	vec_result.y = v.x * m[1]
		+ v.y * m[5]
		+ v.z * m[9];
	vec_result.z = v.x * m[2]
		+ v.y * m[6]
		+ v.z * m[10];
	vec_result.norme = sqrt(vec_result.x * vec_result.x
						+ vec_result.y * vec_result.y
						+ vec_result.z * vec_result.z);
	return (vec_result);
}

t_vector		product_vec_matrix(double *m, t_vector v)
{
	t_vector	vec_result;
	double		w;

	w = v.x * m[3] + v.y * m[7] + v.z * m[11] + m[15];
	vec_result.x = (v.x * m[0]
			+ v.y * m[4]
			+ v.z * m[8]
			+ m[12]) / w;
	vec_result.y = (v.x * m[1]
			+ v.y * m[5]
			+ v.z * m[9]
			+ m[13]) / w;
	vec_result.z = (v.x * m[2]
			+ v.y * m[6]
			+ v.z * m[10]
			+ m[14]) / w;
	vec_result.norme = sqrt(vec_result.x * vec_result.x
						+ vec_result.y * vec_result.y
						+ vec_result.z * vec_result.z);
	return (vec_result);
}
