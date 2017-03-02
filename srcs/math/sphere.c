/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:46:16 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/02 10:37:01 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int		sphere(t_obj obj, t_ray *ray, double *t, t_list **inter)
{
	t_vector	coeffs;
	double		delta;
	t_vector	tmp;

	tmp = vec_diff(ray->org, obj.pos);
	coeffs.x = 1;
	delta = dot_product(ray->dir, tmp);
	coeffs.y = delta + delta;
	coeffs.z = (tmp.norme * tmp.norme) - (obj.r * obj.r);
	if ((delta = (coeffs.y * coeffs.y) - (4 * coeffs.x * coeffs.z)) < ZERO)
		return (0);
	tmp.x = ((double)((-coeffs.y - sqrt(delta)) / (coeffs.x + coeffs.x)));
	tmp.y = ((double)((-coeffs.y + sqrt(delta)) / (coeffs.x + coeffs.x)));
	*t = tmp.y;
	if (tmp.x < tmp.y && tmp.x >= ZERO)
		*t = tmp.x;
	if (*t < ZERO)
		return (0);
	ft_lstadd(inter, ft_lstnew(&tmp, sizeof(t_vector)));
	return (1);
}
