/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:53 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/20 11:45:17 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

/*
 * param[0] --> cos_teta
 * param[1] --> sin_teta
 * param[2] --> cos_phi
 * param[3] --> sin_phi
 */

t_vector	set_up_vector(t_camera *camera, t_vector vec_forward)
{
	t_vector	vec_up;
	double		param[4];
	t_vector	e_r;
	t_vector	rho;

	param[0] = vec_forward.z;
	param[1] = sqrt(1 - param[0] * param[0]);
	e_r = vec_diff(camera->pos, camera->to);
	set_vec(&e_r, 0, 0, e_r.z);
	rho = vec_diff(vec_diff(camera->pos, camera->to), e_r);
	normalize_vec(&rho);
	param[2] = rho.x;
	param[3] = sqrt(1 - param[2] * param[2]);
	set_vec(&vec_up, param[0] * param[2], param[0] * param[3], -param[1]);
	normalize_vec(&vec_up);
	negative_vec(&vec_up);
	return (vec_up);
}

double	*set_camera_matrix(
		t_vector vec_forward, t_vector vec_up,
		t_vector vec_right, t_vector from)
{
	double		*matrix;

	matrix = (double*)malloc(sizeof(double) * 16);
	matrix[0] = vec_right.x;
	matrix[1] = vec_right.y;
	matrix[2] = vec_right.z;
	matrix[3] = 0;
	matrix[4] = vec_up.x;
	matrix[5] = vec_up.y;
	matrix[6] = vec_up.z;
	matrix[7] = 0;
	matrix[8] = vec_forward.x;
	matrix[9] = vec_forward.y;
	matrix[10] = vec_forward.z;
	matrix[11] = 0;
	matrix[12] = from.x;
	matrix[13] = from.y;
	matrix[14] = from.z;
	matrix[15] = 1;
	return (matrix);
}

void			set_camera_data(t_camera *camera)
{
	t_vector	vec_forward;
	t_vector	vec_right;
	t_vector	vec_up;

	vec_forward = vec_diff(camera->pos, camera->to);
	normalize_vec(&vec_forward);
	vec_right = cross_product(set_up_vector(camera, vec_forward), vec_forward);
	vec_up = cross_product(vec_forward, vec_right);
	camera->matrix = set_camera_matrix(vec_forward, vec_up,
			vec_right, camera->pos);
}
