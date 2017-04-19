/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rayon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:59 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/25 13:52:16 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		set_rayon(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->rayon++;
	if (!fill_data(tmp, &new->r))
		return (0);
	if (new->r <= 0)
		return (0);
	return (1);
}
