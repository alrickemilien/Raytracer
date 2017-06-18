/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:08:56 by lvalenti          #+#    #+#             */
/*   Updated: 2017/05/06 13:08:59 by lvalenti         ###   ########.fr       */
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
