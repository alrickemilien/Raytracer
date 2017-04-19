/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:52:02 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/25 14:22:26 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun_struct.h"

t_color	split_color(unsigned long color)
{
	t_color	color_split;

	color_split.red = (color & 0xFF0000) >> 16;
	color_split.green = (color & 0xFF00) >> 8;
	color_split.blue = (color & 0xFF);
	return (color_split);
}
