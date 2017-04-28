/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:49:08 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/25 13:55:09 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <math.h>

int		set_rot(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->rot++;
	if (!fill_data_vec(tmp, &new->rot))
		return (0);
	new->rot.x = new->rot.x * M_PI / (double)180;
	new->rot.y = new->rot.y * M_PI / (double)180;
	new->rot.z = new->rot.z * M_PI / (double)180;
	return (1);
}
