/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:39 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/25 13:52:40 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		set_normal(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->normal++;
	if (!fill_data_vec(tmp, &new->n))
		return (0);
	if (!new->n.z && !new->n.y && !new->n.x)
		return (parse_error(INVALID_NORMAL));
	return (1);
}
