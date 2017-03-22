/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:59 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/22 18:27:16 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int		set_color(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	index->color++;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (*tmp != '(')
		return (parse_error(INVALID_PARAM_FORMAT));
	tmp++;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (!check_data_type_color(tmp))
		return (0);
	tmp += 2;
	int i_tmp = ft_atoi_base(tmp, 16);
	printf("str_color-> %s\n", tmp);
	printf("int_color-> %d\n", i_tmp);
	new->color = split_color(
			mlx_get_color_value(env->mlx, i_tmp));
	new->absorbtion.x = ((double)new->color.red / 255);
	new->absorbtion.y = ((double)new->color.green / 255);
	new->absorbtion.z = ((double)new->color.blue / 255);
	printf("red -> %u green -> %u blue -> %u\n", new->color.red, new->color.green, new->color.blue);
	return (1);
}
