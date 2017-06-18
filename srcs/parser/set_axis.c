/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_axis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:36 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/25 12:22:38 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "vector.h"

int		set_axis(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->axis++;
	if (!fill_data_vec(tmp, &new->axis))
		return (0);
	normalize_vec(&new->axis);
	return (1);
}
