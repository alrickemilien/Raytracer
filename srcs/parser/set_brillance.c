/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_brillance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:51:09 by aemilien          #+#    #+#             */
/*   Updated: 2017/03/25 13:50:53 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		set_brillance(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->brillance++;
	if (!fill_int_data(tmp, &new->brillance))
		return (0);
	if (new->brillance < 0)
		return (0);
	return (1);
}
