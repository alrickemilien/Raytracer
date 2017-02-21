/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:49:08 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/20 14:49:09 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int		set_rotation(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->rotation++;
	if (!fill_data_vec(tmp, &new->rotation))
		return (0);
	new->rotation.x = new->rotation.x * M_PI / (double)180;
	new->rotation.y = new->rotation.y * M_PI / (double)180;
	new->rotation.z = new->rotation.z * M_PI / (double)180;
	return (1);
}
