/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:45:48 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/30 13:16:42 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int				hit_light(t_light light, t_ray *ray, double *t)
{
	t_vector	coeffs;
	double		delta;
	t_vector	tmp;

	tmp = vec_diff(ray->org, light.org);
	coeffs.x = 1;
	delta = dot_product(ray->dir, tmp);
	coeffs.y = delta + delta;
	coeffs.z = (tmp.norme * tmp.norme) - (0.01 * 0.01);
	if ((delta = (coeffs.y * coeffs.y) - ((double)4 * coeffs.x * coeffs.z)) < 0)
		return (0);
	tmp.x = ((double)((-coeffs.y - sqrt(delta)) / (coeffs.x + coeffs.x)));
	tmp.y = ((double)((-coeffs.y + sqrt(delta)) / (coeffs.x + coeffs.x)));
	*t = tmp.y;
	if (tmp.x < tmp.y && tmp.x >= ZERO)
		*t = tmp.x;
	if (*t < ZERO)
		return (0);
	return (1);
}
