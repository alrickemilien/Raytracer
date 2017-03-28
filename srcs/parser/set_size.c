/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:49:15 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/25 13:55:29 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		set_size(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->size++;
	if (!fill_data(tmp, &new->size))
		return (0);
	return (1);
}
