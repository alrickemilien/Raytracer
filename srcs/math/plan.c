/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:45:58 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/03 19:24:24 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"
#include <stdio.h>

int		plan(t_obj *p, t_ray *ray, double *t, t_list **inter)
{
	double		alpha;
	t_range		range;

	alpha = dot_product(ray->org, p->n);
	alpha = dot_product(vec_diff(p->pos, ray->org), p->n) /
			dot_product(ray->dir, p->n);
	if (alpha >= 0)
	{
		*t = alpha;
		range.t1 = (t_inter){alpha, p};
		range.t2 = (t_inter){alpha, p};
		ft_lstadd(inter, ft_lstnew(&range, sizeof(t_range)));
		return (1);
	}
	return (0);
}
