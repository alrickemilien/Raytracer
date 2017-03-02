/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:45:58 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/02 14:32:46 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"
#include <stdio.h>

int		plan(t_obj p, t_ray *ray, double *t, t_list **inter)
{
	double		alpha;
	t_vector	v;

	alpha = dot_product(ray->org, p.n);
	alpha = dot_product(vec_diff(p.pos, ray->org), p.n) /
			dot_product(ray->dir, p.n);
	if (alpha >= 0)
	{
		*t = alpha;
		v.x = alpha;
		v.y = alpha;
		return (1);
	}
	ft_lstadd(inter, ft_lstnew(&alpha, sizeof(double)));
	return (0);
}
