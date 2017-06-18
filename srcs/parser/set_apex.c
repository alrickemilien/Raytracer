/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_apex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:47:30 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/25 12:20:16 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		set_apex(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->apex++;
	if (!fill_data_vec(tmp, &new->apex))
		return (0);
	return (1);
}
