/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:45:58 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/24 18:52:41 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static void		set_range(t_list **inter, t_obj *obj, double t)
{
	t_range		range;

	range.t1 = (t_inter){t, obj};
	range.t2 = (t_inter){t, obj};
	ft_lstadd(inter, ft_lstnew(&range, sizeof(t_range)));
}

int		plan(t_obj *p, t_ray *ray, double *t, t_list **inter)
{
	double		alpha;

	alpha = dot_product(ray->org, p->n);
	alpha = dot_product(vec_diff(p->pos, ray->org), p->n) /
		dot_product(ray->dir, p->n);
	if (alpha >= 0)
	{
		p->pointeur[ray->thread] = p;
		*t = alpha;
		if (inter)
			set_range(inter, p, alpha);
		return (1);
	}
	return (0);
}
