/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_diffuse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:23 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/24 18:34:46 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	get_diffuse(t_vector n, t_vector light_dir)
{
	double	diffuse;

	normalize_vec(&light_dir);
	diffuse = dot_product(light_dir, n);
	if (diffuse < 0)
		return (0);
	return (diffuse);
}
