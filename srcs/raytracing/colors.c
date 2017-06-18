/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbellahc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:49:05 by wbellahc          #+#    #+#             */
/*   Updated: 2017/05/06 13:49:06 by wbellahc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "vector.h"

t_color			moyenne(t_color *tab, int size)
{
	int			color[3];
	t_color		ret;
	int			i;

	ft_bzero(&color, sizeof(int) * 3);
	i = 0;
	while (i < size)
	{
		color[0] += tab[i].blue;
		color[1] += tab[i].green;
		color[2] += tab[i].red;
		i++;
	}
	ret.blue = (unsigned char)(color[0] / size);
	ret.green = (unsigned char)(color[1] / size);
	ret.red = (unsigned char)(color[2] / size);
	return (ret);
}

t_color			scolor(t_color color, double k)
{
	color.red = (unsigned char)((double)color.red * k);
	color.blue = (unsigned char)((double)color.blue * k);
	color.green = (unsigned char)((double)color.green * k);
	return (color);
}

t_color			add_color(t_color current, t_color to_add, double t)
{
	current.red += (unsigned char)(ft_dtrim(0, 255 - current.red,
				((double)to_add.red * t)));
	current.green += (unsigned char)(ft_dtrim(0, 255 - current.green,
				((double)to_add.green * t)));
	current.blue += (unsigned char)(ft_dtrim(0, 255 - current.blue,
				((double)to_add.blue * t)));
	return (current);
}
