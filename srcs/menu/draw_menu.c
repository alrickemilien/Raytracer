/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:09:01 by salibert          #+#    #+#             */
/*   Updated: 2017/05/06 13:34:51 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include <stdio.h>

static void	draw_data(t_image *image, int tmp, t_color color)
{
	image->data[tmp] = color.blue;
	image->data[tmp + 1] = color.green;
	image->data[tmp + 2] = color.red;
}

void		draw_menu(t_data_draw draw, t_image *image)
{
	int		tmp;

	draw.y = draw.tmp_y;
	while (++draw.y < draw.limit_y)
	{
		draw.x = draw.tmp_x;
		while (++draw.x < draw.limit_x)
		{
			tmp = (draw.x * image->bpp) + (draw.y * image->sizeline);
			if (draw.edge && (draw.x >= draw.edge_x1 || draw.y >= draw.edge_y1))
				draw_data(image, tmp, draw.color2);
			else if (draw.edge && (draw.x <= draw.edge_x2
			|| draw.y <= draw.edge_y2))
				draw_data(image, tmp, draw.color3);
			else
			{
				if (!draw.picture)
					draw_data(image, tmp, draw.color1);
				else
					draw_data(image, tmp, mlx_put_xpm(
					draw.x - draw.tmp_x, draw.y - draw.tmp_y, *draw.picture));
			}
		}
	}
}

void		draw_list(t_menu *menu)
{
	t_list	*tmp;

	tmp = menu->button;
	while (tmp)
	{
		draw_menu(*(t_data_draw*)(tmp->content), (menu->page));
		tmp = tmp->next;
	}
}
