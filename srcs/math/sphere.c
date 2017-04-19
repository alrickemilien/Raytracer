/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:46:16 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/24 18:52:00 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static void		set_range(t_list **inter, t_obj *obj, double t1, double t2)
{
	t_range		range;

	range.t1 = (t_inter){t1, obj};
	range.t2 = (t_inter){t2, obj};
	ft_lstadd(inter, ft_lstnew(&range, sizeof(t_range)));
}

int		sphere(t_obj *obj, t_ray *ray, double *t, t_list **inter)
{
	t_vector	coeffs;
	double		delta;
	t_vector	tmp;

	tmp = vec_diff(ray->org, obj->pos);
	coeffs.x = 1;
	delta = dot_product(ray->dir, tmp);
	coeffs.y = delta + delta;
	coeffs.z = (tmp.norme * tmp.norme) - (obj->r * obj->r);
	if ((delta = (coeffs.y * coeffs.y) - (4 * coeffs.x * coeffs.z)) < ZERO)
		return (0);
	tmp.x = ((double)((-coeffs.y - sqrt(delta)) / (coeffs.x + coeffs.x)));
	tmp.y = ((double)((-coeffs.y + sqrt(delta)) / (coeffs.x + coeffs.x)));
	*t = tmp.y;
	if (tmp.x < tmp.y && tmp.x >= ZERO)
		*t = tmp.x;
	if (*t < ZERO)
		return (0);
	obj->pointeur[ray->thread] = obj;
	if (inter)
		set_range(inter, obj, tmp.x, tmp.y);
	return (1);
}
