/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shining.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbellahc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:50:04 by wbellahc          #+#    #+#             */
/*   Updated: 2017/05/06 13:50:06 by wbellahc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "rtv1.h"

static t_color		compute_color(t_list *l, double d, double tmp, t_color c)
{
	d = acos(d);
	d = ((t_light*)(l->content))->intensity
		* exp(-pow((d / (0.2 * (1 / tmp))), 2));
	c.blue += (unsigned char)(ft_dtrim(0, 255 - c.blue,
			255 * d * (10 / tmp)));
	c.red += (unsigned char)(ft_dtrim(0, 255 - c.red,
			255 * d * (10 / tmp)));
	c.green += (unsigned char)(ft_dtrim(0, 255 - c.green,
			255 * d * (10 / tmp)));
	return (c);
}

t_color				shining(t_list *l, t_ray *ray, double *norme)
{
	double			d;
	t_color			c;
	t_vector		light_vec;
	double			tmp;

	ft_bzero(&c, sizeof(t_color));
	*norme = 2000000;
	while (l)
	{
		if (((t_light*)(l->content))->shining)
		{
			light_vec = vec_diff(((t_light*)(l->content))->org, ray->org);
			if (light_vec.norme < *norme)
				*norme = light_vec.norme;
			tmp = light_vec.norme;
			normalize_vec(&light_vec);
			if ((d = dot_product(light_vec, ray->dir)) > 0)
				c = compute_color(l, d, tmp, c);
		}
		l = l->next;
	}
	return (c);
}
