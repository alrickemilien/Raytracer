/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_diffuse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:48:24 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/25 13:57:35 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		set_diffuse(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->diffuse++;
	if (!fill_data(tmp, &new->diffuse))
		return (0);
	if (new->diffuse < 0 || new->diffuse > 1)
		return (parse_error(BAD_COEFF));
	return (1);
}
