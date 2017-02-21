/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_axis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:36 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:47:37 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int		set_axis(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->axis++;
	if (!fill_data_vec(tmp, &new->axis))
		return (0);
	normalize_vec(&new->axis);
	return (1);
}
