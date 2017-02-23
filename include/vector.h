/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:18:23 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/23 11:19:56 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include <stdlib.h>

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	double		norme;
}				t_vector;

t_vector		cross_product(t_vector a, t_vector b);
double			dot_product(t_vector a, t_vector b);
void			set_vec(t_vector *v, double x, double y, double z);
void			normalize_vec(t_vector *vector);
t_vector		vec_diff(t_vector a, t_vector b);
t_vector		n_vec(t_vector v, double n);
t_vector		vec_add(t_vector a, t_vector b);
void			negative_vec(t_vector *v);

t_vector		product_vec_matrix(double *m, t_vector v);
t_vector		product_matrix4x4(double *m, t_vector v);
int				is_vectornull(t_vector v);

#endif
