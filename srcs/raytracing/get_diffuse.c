/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_diffuse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:23 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 17:04:24 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	get_diffuse(t_vector n, t_vector light_dir)
{
	double	diffuse;

	normalize_vec(&light_dir);
	diffuse = dot_product(light_dir, n);
	if (diffuse < 0)
		return (0);
	return (diffuse);
}
