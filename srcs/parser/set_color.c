/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:59 by aemilien          #+#    #+#             */
/*   Updated: 2017/04/25 09:53:49 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		set_color(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	int i_tmp;

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
	i_tmp = ft_atoi_base(tmp, 16);
	new->color = split_color(
			mlx_get_color_value(env->addr_mlx, i_tmp));
	new->absorbtion.x = ((double)new->color.red / 255);
	new->absorbtion.y = ((double)new->color.green / 255);
	new->absorbtion.z = ((double)new->color.blue / 255);
	return (1);
}
