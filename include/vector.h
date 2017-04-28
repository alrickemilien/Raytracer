/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:18:23 by aemilien          #+#    #+#             */
/*   Updated: 2017/04/28 10:57:32 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "commun_struct.h"
# include <math.h>

t_vector			*arthmetic_box(t_obj obj, t_obj *plan_tab);
void				set_spaces_diff(t_range *a, t_range *b);
t_vector			cross_product(t_vector a, t_vector b);
double				dot_product(t_vector a, t_vector b);
void				set_vec(t_vector *v, double x, double y, double z);
void				normalize_vec(t_vector *vector);
t_vector			vec_diff(t_vector a, t_vector b);
t_vector			n_vec(t_vector v, double n);
t_vector			vec_add(t_vector a, t_vector b);
void				negative_vec(t_vector *v);
t_vector			product_vec_matrix(double *m, t_vector v);
t_vector			product_matrix4x4(double *m, t_vector v);
int					is_vectornull(t_vector v);
t_vector			get_vec(double x, double y, double z);
int					betwx(double t, double n1, double n2);
double				*inv_m(double *m);
void				swap(double *a, double *b);
int					betwn(double t, double n1, double n2);
double				fresnel(t_ray ray, t_surface s);
t_color				beers_law(t_color color, t_obj *obj, t_surface s, t_ray ray);
double				*set_rot_m(double *matrix, double alpha,
											double beta, double gamma);
double  			*set_camera_matrix(
							t_vector vec_forward, t_vector vec_up,
							t_vector vec_right, t_vector from);
void				set_color_coeff(t_env *env, t_surface s,
									t_obj *tmp, double *t);
double				shadow(t_env *env, t_ray ray, double norme);
double				get_specularity(t_vector intersection, t_vector n,
		t_vector light_dir, t_obj *obj);
double				get_diffuse(t_vector n, t_vector light_dir);
t_surface			get_surface_caracter(t_ray ray, t_obj *tmp);
t_ray				get_reflection(t_surface s, t_ray ray);
t_ray				get_refraction(t_surface s, t_ray ray);
t_vector			get_surface_normal(t_vector intersection,
		t_obj *tmp, t_ray ray);
void				rotate_object(t_obj *object, t_vector *vector);
void				rotate_vec(t_vector rot, t_vector *vector);
double				range(double a, double b);
#endif
