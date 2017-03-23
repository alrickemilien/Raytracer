/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:43 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/23 15:29:19 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	mlx_put_pixel_to_image(t_image *image, int x, int y, t_color color)
{
	int		tmp;

	tmp = (x * (image->bpp)) + (y * image->sizeline);
	image->data[tmp] = color.blue;
	image->data[tmp + 1] = color.green;
	image->data[tmp + 2] = color.red;
}