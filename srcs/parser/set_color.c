/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:59 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:48:02 by aemilien         ###   ########.fr       */
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
	new->color = split_color(
			mlx_get_color_value(env->mlx, ft_atoi_base(tmp, 16)));
	return (1);
}
